/*
 * I2C-Generator: 0.3.0
 * Yaml Version: 2.1.3
 * Template Version: 0.7.0-112-g190ecaa
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 * (license text unchanged)
 */

#include <Arduino.h>
#include <SensirionI2CSen5x.h>
#include <Wire.h>

// The used commands use up to 48 bytes. On some Arduino's the default buffer
// space is not large enough
#define MAXBUF_REQUIREMENT 48

#if (defined(I2C_BUFFER_LENGTH) &&                 \
     (I2C_BUFFER_LENGTH >= MAXBUF_REQUIREMENT)) || \
    (defined(BUFFER_LENGTH) && BUFFER_LENGTH >= MAXBUF_REQUIREMENT)
#define USE_PRODUCT_INFO
#endif

SensirionI2CSen5x sen5x;

static void printModuleVersions() {
    uint16_t error;
    char errorMessage[256];

    unsigned char productName[32];
    uint8_t productNameSize = 32;

    error = sen5x.getProductName(productName, productNameSize);
    if (error) {
        Serial.print("Error trying to execute getProductName(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    } else {
        Serial.print("ProductName:");
        Serial.println((char*)productName);
    }

    uint8_t firmwareMajor, firmwareMinor, hardwareMajor, hardwareMinor;
    uint8_t protocolMajor, protocolMinor;
    bool firmwareDebug;

    error = sen5x.getVersion(firmwareMajor, firmwareMinor, firmwareDebug,
                             hardwareMajor, hardwareMinor, protocolMajor,
                             protocolMinor);
    if (error) {
        Serial.print("Error trying to execute getVersion(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    } else {
        Serial.print("Firmware: ");
        Serial.print(firmwareMajor);
        Serial.print(".");
        Serial.print(firmwareMinor);
        Serial.print(", ");

        Serial.print("Hardware: ");
        Serial.print(hardwareMajor);
        Serial.print(".");
        Serial.println(hardwareMinor);
    }
}

static void printSerialNumber() {
    uint16_t error;
    char errorMessage[256];
    unsigned char serialNumber[32];
    uint8_t serialNumberSize = 32;

    error = sen5x.getSerialNumber(serialNumber, serialNumberSize);
    if (error) {
        Serial.print("Error trying to execute getSerialNumber(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    } else {
        Serial.print("SerialNumber:");
        Serial.println((char*)serialNumber);
    }
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    Wire.begin();
    sen5x.begin(Wire);

    uint16_t error;
    char errorMessage[256];

    error = sen5x.deviceReset();
    if (error) {
        Serial.print("Error trying to execute deviceReset(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    }

#ifdef USE_PRODUCT_INFO
    printSerialNumber();
    printModuleVersions();
#endif

    // Optional: temperature offset (SEN54/SEN55 only)
    float tempOffset = 0.0f;
    error = sen5x.setTemperatureOffsetSimple(tempOffset);
    if (error) {
        Serial.print("Error trying to execute setTemperatureOffsetSimple(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    } else {
        Serial.print("Temperature Offset set to ");
        Serial.print(tempOffset);
        Serial.println(" deg. Celsius (SEN54/SEN55 only");
    }

    // Start measurement
    error = sen5x.startMeasurement();
    if (error) {
        Serial.print("Error trying to execute startMeasurement(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    }
    delay(4000);
    sen5x.startFanCleaning();
    // Give the sensor time to produce the first dataset
    delay(60000);
}

void loop() {
    uint16_t error;
    char errorMessage[256];

    // Variables for readMeasuredPmValues()
    float massConcentrationPm1p0;
    float massConcentrationPm2p5;
    float massConcentrationPm4p0;
    float massConcentrationPm10p0;

    float numberConcentrationPm0p5;
    float numberConcentrationPm1p0;
    float numberConcentrationPm2p5;
    float numberConcentrationPm4p0;
    float numberConcentrationPm10p0;

    float typicalParticleSize;
    delay(1000);
    // Read particulate measurements only
    error = sen5x.readMeasuredPmValues(
        massConcentrationPm1p0, massConcentrationPm2p5, massConcentrationPm4p0,
        massConcentrationPm10p0, numberConcentrationPm0p5,
        numberConcentrationPm1p0, numberConcentrationPm2p5,
        numberConcentrationPm4p0, numberConcentrationPm10p0,
        typicalParticleSize);

    if (error) {
        Serial.print("Error trying to execute readMeasuredPmValues(): ");
        errorToString(error, errorMessage, sizeof(errorMessage));
        Serial.println(errorMessage);
    } else {
        // Mass concentrations [µg/m³]
        Serial.print("MassConcentrationPm1p0:");
        Serial.print(massConcentrationPm1p0);
        Serial.print("\tMassConcentrationPm2p5:");
        Serial.print(massConcentrationPm2p5);
        Serial.print("\tMassConcentrationPm4p0:");
        Serial.print(massConcentrationPm4p0);
        Serial.print("\tMassConcentrationPm10p0:");
        Serial.print(massConcentrationPm10p0);

        // Number concentrations [#/cm³]
        Serial.print("\tNumberConcentrationPm0p5:");
        if (isnan(numberConcentrationPm0p5)) Serial.print("n/a");
        else Serial.print(numberConcentrationPm0p5);

        Serial.print("\tNumberConcentrationPm1p0:");
        if (isnan(numberConcentrationPm1p0)) Serial.print("n/a");
        else Serial.print(numberConcentrationPm1p0);

        Serial.print("\tNumberConcentrationPm2p5:");
        if (isnan(numberConcentrationPm2p5)) Serial.print("n/a");
        else Serial.print(numberConcentrationPm2p5);

        Serial.print("\tNumberConcentrationPm4p0:");
        if (isnan(numberConcentrationPm4p0)) Serial.print("n/a");
        else Serial.print(numberConcentrationPm4p0);

        Serial.print("\tNumberConcentrationPm10p0:");
        if (isnan(numberConcentrationPm10p0)) Serial.print("n/a");
        else Serial.print(numberConcentrationPm10p0);

        // Typical particle size [µm]
        Serial.print("\tTypicalParticleSize:");
        if (isnan(typicalParticleSize)) Serial.println("n/a");
        else Serial.println(typicalParticleSize);


        delay(1000);
        Serial.println("\n\n\n\n\n");
        uint32_t status_before = 0;
        uint16_t err = sen5x.readAndClearDeviceStatus(status_before);
        if (err == 0) {
          char buf[11];
          snprintf(buf, sizeof(buf), "0x%08lX", (unsigned long)status_before);
          Serial.println(buf);
        }
        Serial.println("\n\n\n\n\n");
        delay(1000);
    }

    delay(1000);
}
