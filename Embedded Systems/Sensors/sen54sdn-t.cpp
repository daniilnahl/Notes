//Only works in arduino IDE
#include <Arduino.h>
#include <SensirionI2CSen5x.h>
#include <Wire.h>

#define MAXBUF_REQUIREMENT 48
#if (defined(I2C_BUFFER_LENGTH) && (I2C_BUFFER_LENGTH >= MAXBUF_REQUIREMENT)) || \
    (defined(BUFFER_LENGTH) && BUFFER_LENGTH >= MAXBUF_REQUIREMENT)
#define USE_PRODUCT_INFO
#endif

SensirionI2CSen5x sen5x;

static void printDeviceIdentity() {
  char name[32] = {0};
  uint16_t err = sen5x.getProductName((unsigned char*)name, sizeof(name));
  if (!err) {
    Serial.print("Product: ");
    Serial.println(name);
  }

  uint8_t fwMaj, fwMin, hwMaj, hwMin, protoMaj, protoMin;
  bool fwDebug = false;  // <-- must be bool for getVersion's 3rd parameter

  err = sen5x.getVersion(fwMaj, fwMin, fwDebug, hwMaj, hwMin, protoMaj, protoMin);
  if (!err) {
    Serial.print("FW "); Serial.print(fwMaj); Serial.print('.'); Serial.print(fwMin);
    if (fwDebug) Serial.print(" (debug)");
    Serial.print("  HW "); Serial.print(hwMaj); Serial.print('.'); Serial.print(hwMin);
    Serial.print("  Proto "); Serial.print(protoMaj); Serial.print('.'); Serial.println(protoMin);
  } else {
    char msg[256];
    errorToString(err, msg, sizeof(msg));
    Serial.print("getVersion(): "); Serial.println(msg);
  }
}


static void checkDeviceStatus() {
  uint32_t status = 0;
  uint16_t err = sen5x.readDeviceStatus(status);
  if (err) return;
  // Datasheet §5.4: bit5 LASER, bit4 FAN, bit21 SPEED. :contentReference[oaicite:5]{index=5} :contentReference[oaicite:6]{index=6}
  bool laserErr = (status & (1u << 5));
  bool fanErr   = (status & (1u << 4));
  bool speedOut = (status & (1u << 21));
  if (laserErr || fanErr || speedOut) {
    Serial.print("⚠ DeviceStatus 0x"); Serial.println(status, HEX);
    if (laserErr) Serial.println("  LASER error flagged");
    if (fanErr)   Serial.println("  FAN error flagged");
    if (speedOut) Serial.println("  FAN speed out of range");
  }
}

static bool waitForDataReady(uint32_t timeout_ms) {
  const uint32_t t0 = millis();
  for (;;) {
    bool ready = false;
    uint16_t err = sen5x.readDataReady(ready);   // library API
    if (!err && ready) return true;
    if (millis() - t0 > timeout_ms) return false;
    delay(25);
  }
}

// One-time probe to see if any PM channels are 0xFFFF (→ 6553.5)
static void probeForSentinels() {
  uint16_t e;
  uint16_t pm1, pm25, pm4, pm10;
  int16_t rh, t, voc, nox;  // signed per table; we won’t use them here
  e = sen5x.readMeasuredValuesAsIntegers(pm1, pm25, pm4, pm10, rh, t, voc, nox);
  if (e) return;
  auto isFFFF = [](uint16_t v){ return v == 0xFFFFu; }; // :contentReference[oaicite:7]{index=7}
  if (isFFFF(pm1) || isFFFF(pm25) || isFFFF(pm4) || isFFFF(pm10)) {
    Serial.println("❌ PM sentinel detected (0xFFFF).");
    Serial.println("   Causes: RHT/Gas-Only mode, not yet measuring, or internal fault.");
    checkDeviceStatus();
  } else {
    Serial.println("✅ PM channels look valid (no 0xFFFF).");
  }
}

void SetupSen54() {
  sen5x.begin(Wire);

  uint16_t error;
  char errorMessage[256];

  error = sen5x.deviceReset();
  if (error) {
    Serial.print("deviceReset(): ");
    errorToString(error, errorMessage, sizeof(errorMessage));
    Serial.println(errorMessage);
  }
  delay(10);

  printDeviceIdentity();

  // Optional: set a known temperature offset (datasheet §6.1.6) :contentReference[oaicite:8]{index=8}
  float tempOffset = 0.0f;
  error = sen5x.setTemperatureOffsetSimple(tempOffset);
  if (error) {
    Serial.print("setTemperatureOffsetSimple(): ");
    errorToString(error, errorMessage, sizeof(errorMessage));
    Serial.println(errorMessage);
  }

  // Start full Measurement mode (NOT RHT/Gas-Only). Datasheet §6.1.1/6.1.2. :contentReference[oaicite:9]{index=9}
  error = sen5x.startMeasurement();
  if (error) {
    Serial.print("startMeasurement(): ");
    errorToString(error, errorMessage, sizeof(errorMessage));
    Serial.println(errorMessage);
  }

  // Do NOT run a fan-clean immediately; measurement pauses during cleaning. :contentReference[oaicite:10]{index=10}
  // Call startFanCleaning() later on demand.

  // Gate on data-ready to avoid stale/undefined frames. Datasheet §6.1.4/6.1.5. :contentReference[oaicite:11]{index=11}
  if (!waitForDataReady(3000)) {
    Serial.println("⏳ No data-ready after 3s; continuing but first read may be old/empty.");
  }

  // Quick health probe: look for 0xFFFF sentinels once.
  probeForSentinels();

  // OPTIONAL: extended warmup for optics/flow stability if you want (up to ~90 s).
  // delay(90000);
}

static void dumpRawOnce() {
  uint16_t e;
  uint16_t pm1, pm25, pm4, pm10;
  int16_t rh, t, voc, nox;  // signed as per API
  e = sen5x.readMeasuredValuesAsIntegers(pm1, pm25, pm4, pm10, rh, t, voc, nox);
  if (e) { Serial.println("readMeasuredValuesAsIntegers() error"); return; }

  auto pr = [](const char* n, uint16_t v){
    Serial.print(n); Serial.print("=0x"); Serial.print(v, HEX);
    if (v == 0xFFFFu || v == 0xFFFEu) Serial.print(" (SENTINEL)");
    Serial.print("  ");
  };
  pr("PM1", pm1); pr("PM2.5", pm25); pr("PM4", pm4); pr("PM10", pm10);
  Serial.println();
}

void LoopSen54() {
  uint16_t error;
  char errorMessage[256];

  // Poll data-ready; the device updates once per second. :contentReference[oaicite:12]{index=12}
  if (!waitForDataReady(1500)) {
    // No fresh data this cycle; check status and bail early.
    checkDeviceStatus();
    return;
  }

  float pm1, pm25, pm4, pm10, rh, temp, voc, nox;
  error = sen5x.readMeasuredValues(pm1, pm25, pm4, pm10, rh, temp, voc, nox);
  if (error) {
    Serial.print("readMeasuredValues(): ");
    errorToString(error, errorMessage, sizeof(errorMessage));
    Serial.println(errorMessage);
    return;
  }


  // Flag any sentinel-looking floats (~6553.x)
  auto bad = [](float v){ return v >= 6553.0f && v <= 6553.6f; };

  if (bad(pm25) || bad(pm4) || bad(pm10)) {
    Serial.println("⚠ PM fields show sentinel (~6553.x) -> check address/frames.");
    dumpRawOnce();  // see exact 0xFFFF/0xFFFE status
  }

  // Print; if any PM still shows ~6553.x, that’s a sentinel via library scaling (0xFFFF/10). :contentReference[oaicite:13]{index=13}
  Serial.print("PM1: ");   Serial.print(pm1);   Serial.print("\t");
  Serial.print("PM2.5: "); Serial.print(pm25);  Serial.print("\t");
  Serial.print("PM4: ");   Serial.print(pm4);   Serial.print("\t");
  Serial.print("PM10: ");  Serial.print(pm10);  Serial.print("\t");
  Serial.print("RH: ");    Serial.print(isnan(rh) ? NAN : rh);        Serial.print("\t");
  Serial.print("T: ");     Serial.print(isnan(temp) ? NAN : temp);    Serial.print("\t");
  Serial.print("VOCi: ");  Serial.print(isnan(voc) ? NAN : voc);      Serial.print("\t");
  Serial.print("NOxi: ");  Serial.println(isnan(nox) ? NAN : nox);

}

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(50);
  Wire.begin();
  SetupSen54();
  delay(60000);
}

void loop() {
  LoopSen54();
  delay(50);

  uint32_t status = 0;
uint16_t err = sen5x.readDeviceStatus(status);   // returns 0 on success
if (err == 0) {
  Serial.printf("DeviceStatus = 0x%08lX\n", status);
  if (status & (1u << 21)) Serial.println("SPEED: fan speed out of range");
  if (status & (1u << 19)) Serial.println("FAN: cleaning active");
  if (status & (1u << 7))  Serial.println("GAS SENSOR error (VOC/NOx)");
  if (status & (1u << 6))  Serial.println("RHT comms error");
  if (status & (1u << 5))  Serial.println("LASER failure");
  if (status & (1u << 4))  Serial.println("FAN failure");
} else {
  char msg[128];
  errorToString(err, msg, sizeof(msg));
  Serial.print("readDeviceStatus(): "); Serial.println(msg);
}

}
