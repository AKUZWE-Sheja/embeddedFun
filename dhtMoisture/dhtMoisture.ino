#include <DHT11.h>

const int soilPin = A0; 
const int relayPin = 15;
int soilMoistureValue;


DHT11 dht11(13);

void setup() {
    Serial.begin(9600);
    pinMode(relayPin, OUTPUT);
}

void loop() {
    soilMoistureValue = analogRead(soilPin);

    Serial.print("Soil Moisture: ");
    Serial.println(soilMoistureValue);

    int temperature = dht11.readTemperature();

    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
    } else {
        Serial.println(DHT11::getErrorString(temperature));
    }

    if (soilMoistureValue > 1000) {
        digitalWrite(relayPin, HIGH);
    } else if (soilMoistureValue < 500) {
        digitalWrite(relayPin, LOW);
    }

    delay(1000); 
}
