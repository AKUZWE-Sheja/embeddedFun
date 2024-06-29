#include <SoftwareSerial.h>

const byte rxPin = 0;
const byte txPin = 1;

SoftwareSerial esp8266(rxPin, txPin); //SoftwareSerial esp8266(0, 1); // RX, TX (connect RX to TX and TX to RX on ESP8266)

int gasPin = 2;
int ledPin = 8;
int buzzerPin = 4;

void setup() {
  pinMode(gasPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  esp8266.begin(9600); //defining voltage for the serial communication
  sendCommand("AT+CMGF=1"); //Setting my modem to SMS mode
} 

void loop() {
  int gasValue = digitalRead(gasPin);
  
  if (gasValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Gas leakage detected!");
    delay(1000);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(1000);
  }
}

void sendCommand(String cmd) {
  esp8266.println(cmd);
  delay(1000);
  while (esp8266.available()) {
    Serial.println(esp8266.readStringUntil('\n'));
  }
} 

void sendSMS(String message) {
  sendCommand("AT+CMGS=\"+250788743328\"");
  sendCommand(message);
  esp8266.write(0x1A); //Indicating the end of message with SUB like Ctrl + Z
  delay(2000);
}

