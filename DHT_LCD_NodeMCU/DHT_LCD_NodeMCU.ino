#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define LED D5            // Led in NodeMCU at pin GPIO16 (D0).
#define DHTPIN D6
#define DHTTYPE DHT11   // DHT 11


// int LED = 5;
// int DHTPIN = 6;


LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
float h,t;

void setup() {
  pinMode(LED, OUTPUT);    // LED pin as output.
  dht.begin();

  // LCD setting
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, World!");
  
  // Serial communication setting
  Serial.begin(9600);   
  Serial.print("Hello nodemcu");
}

void loop() {
  digitalWrite(LED, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually 
                          // the LED is on; this is because it is active low on the ESP8266.
  delay(1000);            // wait for 1 second.
  digitalWrite(LED, LOW); // turn the LED on.
  delay(1000); // wait for 1 second.
  h = dht.readHumidity();
  t = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(t);
  Serial.print("H:");
  Serial.print(h);
  Serial.print(" T:");
  Serial.println(t);
}



// 출처: https://bcho.tistory.com/1288 [조대협의 블로그]
