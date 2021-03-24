#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel RGB_LED = Adafruit_NeoPixel(3, 6, NEO_GRB);

void setup() {
  RGB_LED.begin();
  RGB_LED.setBrightness(50); //RGB_LED 밝기조절
  RGB_LED.clear();
}

void loop() {
  RGB_Color(RGB_LED.Color(225, 0, 0), 500); //RED
  RGB_Color(RGB_LED.Color(0, 255, 0), 500); //GREEN
  RGB_Color(RGB_LED.Color(0, 0, 255), 500); //BLUE
}

void RGB_Color(float c, int wait) {
  for (int i = 0; i < 3; i++) {
    RGB_LED.setPixelColor(i, c);
    RGB_LED.show();
  }
  delay(wait);
}
