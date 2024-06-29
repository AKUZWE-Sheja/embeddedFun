#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX
 void setup() {
    Serial.begin(9600);
    BTSerial.begin(9600);
 }
 void loop() {
    if (BTSerial.available()) {
        Serial.print("Aggy: ");
        String message = BTSerial.readStringUntil('\n');
        Serial.print(message);
        Serial.println();
    }
    if (Serial.available()) {
        Serial.print("Edwige: ");
        String message = Serial.readStringUntil('\n');
        BTSerial.print(message);
        Serial.print(message);
        Serial.println();
    }
 }



