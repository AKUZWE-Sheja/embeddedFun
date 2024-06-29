#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String userMessage = Serial.readStringUntil('\n');
    Serial.println("Me: " + userMessage);

    mySerial.println(userMessage);
  }

  if (mySerial.available()) {
    String responseData = mySerial.readStringUntil('\n');
    Serial.println("Daniella: " + responseData);
  }
}
