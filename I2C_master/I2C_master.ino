#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(9);
  Wire.write("Hello Daniella The Slave!");
  Wire.endTransmission();

  delay(1000);
}
