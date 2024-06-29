int gasPin = 2;
int ledPin = 8;
int buzzerPin = 4;

void setup() {
  pinMode(gasPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasPin);
  Serial.print("Gas Value: "); 
  Serial.println(gasValue);
  
  if (gasValue > 150) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Gas detected!");
    Serial.println("ALERT: Gas detected!");
    delay(1000);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(1000);
  }
  else{
    Serial.println("Safe");
  }
}