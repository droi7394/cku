#include <Wire.h>                            // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>            // LCD 1602 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27, 16, 2);       // 접근주소: 0x3F or 0x27

void setup()
{
  lcd.init();  // LCD 초기화
}

void loop()
{
  lcd.backlight();                        // 백라이트 켜기
  lcd.setCursor(0, 0);                     // 0번째, 0라인
  lcd.print("Hello world!");
  lcd.setCursor(0, 1);                       // 1번째, 1라인
  lcd.print("Enjoy eduino!");
}
