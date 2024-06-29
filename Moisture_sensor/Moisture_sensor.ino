#define MOISTURE_SENSOR_PIN 2
#define GREEN_LED 8
#define RED_LED 7

void setup() {
  // Initializing serial communication for HC-05
  Serial.begin(9600);

  // Set the LED pins as output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // Read the value from the moisture sensor
  int moistureLevel = digitalRead(MOISTURE_SENSOR_PIN);

  // Send the moisture level to the connected Bluetooth device
  Serial.println(moistureLevel);

  // If the moisture level is below the threshold (for example, 300), turn on LED1
  if (moistureLevel == HIGH) {

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  // Otherwise, turn on LED2
  else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }

  // Wait for a second before the next reading
  delay(5000);
}
