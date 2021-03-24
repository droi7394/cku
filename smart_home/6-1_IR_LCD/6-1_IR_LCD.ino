#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 or 0x3F

int IRPin = 10;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(IRPin, INPUT);
}

void loop() {
  if (digitalRead(IRPin) == LOW) {
    lcd.setCursor(0, 0); lcd.print(" !!emergency!! ");
    lcd.setCursor(0, 1); lcd.print("  IRsensor on   ");
  }
  else {
    lcd.setCursor(0, 0); lcd.print("Security system ");
    lcd.setCursor(0, 1); lcd.print("  IRsensor off  ");
  }
}
