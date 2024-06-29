// #include <LiquidCrystal_I2C.h>
// LiquidCrystal_I2C lcd(0x27,16,2); 
// void setup() {
// lcd.init();
// lcd.clear();
// lcd.backlight(); 
// // Print a message on both lines of the LCD.
// lcd.setCursor(0,0); 
// lcd.print("He ain tellin u");
// lcd.setCursor(0,1); 
// lcd.print("notin u don know");
// }
// void loop(){}



// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address and dimensions

// byte big_heart[8] = {
//   B00000,
//   B01110,
//   B10001,
//   B10001,
//   B10001,
//   B10001,
//   B01110,
//   B00000
// };


// void setup() {
//   lcd.init();
//   lcd.backlight();
//   lcd.createChar(0, big_heart);
// }

// void loop() {
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("If he can't");
//   lcd.setCursor(0, 1);
//   lcd.print("provide for u");
//   delay(2000);
  
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("mentally, what's the");
//   lcd.setCursor(0, 1);
//   lcd.print("point of staying");
//   delay(2000);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("for the bullshit?");
//   lcd.setCursor(0, 1);
//   lcd.print("Hhehehe");
//   delay(2000);
// }


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address and dimensions

byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, heart); 
  lcd.createChar(1, smiley);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("All of me ");
  lcd.write(0);  
  lcd.setCursor(0, 1);
  lcd.print("loves all of u ");
  lcd.write(1);  
  delay(2000);
}


