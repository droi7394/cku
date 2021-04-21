//****************** 스마트 전등 함수 ******************//
void Smart_light(int R, int G, int B) {       // RGB_Color 함수의 매게변수가 R,G,B로 3개이다.
  float LED_Color = RGB_LED.Color(R, G, B);   // pixel의 색 저장.
  for (int i = 0; i < 3 ; i++) {
    RGB_LED.setPixelColor(i, LED_Color);      // i와 동일한 순서의 pixel의 색을 LED_color로 지정.
    RGB_LED.show();
    delay(10);
  }
  Serial.print("R: "); Serial.print(R_Val);
  Serial.print(", G: "); Serial.print(G_Val);
  Serial.print(", B: "); Serial.println(B_Val);
}
