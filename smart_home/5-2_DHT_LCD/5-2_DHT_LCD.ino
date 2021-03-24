#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 or 0x3F

#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("T : "); lcd.print((int)temp); lcd.print("C");
  lcd.setCursor(8, 0);
  lcd.print("H : "); lcd.print((int)hum); lcd.print("%");

  if (temp >= 30)
  {
    lcd.setCursor(0, 1);
    lcd.print("T :"); lcd.print("HIGH");
  }
  else if (temp < 30)
  {
     lcd.setCursor(0, 1);
    lcd.print("T : "); lcd.print("LOW ");
  }

    if (hum >= 60)
  {
    lcd.setCursor(8, 1);
    lcd.print("H :"); lcd.print("HIGH");
  }
  else if ( temp < 60)
  {
     lcd.setCursor(8, 1);
    lcd.print("H : "); lcd.print("LOW ");
  }
}
