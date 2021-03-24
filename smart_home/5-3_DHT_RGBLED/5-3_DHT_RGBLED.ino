#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel RGB_LED = Adafruit_NeoPixel(3, 6, NEO_GRB);
int R_Val, G_Val, B_Val = 0;

void setup() {
  dht.begin();
  RGB_LED.begin();
  RGB_LED.setBrightness(100);
  RGB_LED.show();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  float discomfort_index = ((9 * temp) / 5) - ((0.55 * (1 - (hum / 100))) * (((9 * temp) / 5) - 26)) + 32;


  if ((int)discomfort_index >= 80) {
    Smart_light(255, 000, 000);
  }
  else if ((int)discomfort_index < 80) {
    Smart_light(000, 000, 255);
  }
}

void Smart_light(int R, int G, int B) {
  float LED_Color = RGB_LED.Color(R, G, B);
  for (int i = 0; i < 3 ; i++) {
    RGB_LED.setPixelColor(i, LED_Color);
    RGB_LED.show();
    delay(10);
  }
  Serial.print("R: "); Serial.print(R_Val);
  Serial.print(", G: "); Serial.print(G_Val);
  Serial.print(", B: "); Serial.println(B_Val);
}
