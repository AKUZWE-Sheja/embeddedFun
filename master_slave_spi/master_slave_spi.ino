#include <SPI.h>

const int slaveSelectPin = 10; // Pin 10 is connected to slave's SS pin

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  SPI.begin(); // Initialize SPI communication
  pinMode(slaveSelectPin, OUTPUT); // Set slave select pin as output
  digitalWrite(slaveSelectPin, HIGH); // Deselect the slave initially
}

void loop() {
  digitalWrite(slaveSelectPin, LOW); 
  delay(10); 

  SPI.transfer('H'); 
  delay(10);
  SPI.transfer('i'); 
  delay(10);
  digitalWrite(slaveSelectPin, HIGH); 
  delay(1000);

//   String message = "Hello, Ariane!";
// int messageLength = message.length(); // Get the length of the message

// digitalWrite(slaveSelectPin, LOW); // Select the slave
// delay(10); // Wait for slave to get ready

// for (int i = 0; i < messageLength; i++) {
//   SPI.transfer(message[i]); // Send each character of the message
//   delay(10);
// }

// digitalWrite(slaveSelectPin, HIGH); // Deselect the slave
// delay(1000);

}
