/***
 * I2C Scanner for Arduino
 * this sketch scans the I2C bus for connected devices and prints their addresses.
 */

#include <Wire.h>

// Define your SDA and SCL pins here, exactly as in your BME280 sketch
#define I2C_SDA_PIN 8 // <<< CHANGE THIS to your chosen SDA pin
#define I2C_SCL_PIN 9 // <<< CHANGE THIS to your chosen SCL pin

void setup() {
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN); // Initialize I2C with your custom pins
}

void loop() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
  delay(5000); // Wait 5 seconds for next scan
}