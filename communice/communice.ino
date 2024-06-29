#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
void setup() {
Serial.begin(9600);
mySerial.begin(9600);
}
void loop() {
String responseData = mySerial.readStringUntil('\n');
Serial.println("Sending data from Arduino1...");
mySerial.println("Hiii");
Serial.println(responseData);
delay(1000);
}