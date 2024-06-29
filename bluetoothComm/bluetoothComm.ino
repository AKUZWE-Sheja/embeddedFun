#include <SoftwareSerial.h>
SoftwareSerial bt(10,11);
void setup() {
  Serial.begin(38400);
  bt.begin(38400);
}
void loop() {
  if(bt.available()){
    Serial.print(bt.readString());
  }
  if(Serial.available()){
    bt.write(Serial.read());
  }
}