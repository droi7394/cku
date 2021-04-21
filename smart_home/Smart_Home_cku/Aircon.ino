//****************** 스마트 에어콘 함수 ******************//
void Smart_Air(int fan_speeds) {              // 온습도 센서의 값과 불쾌지수 값을 출력하는 함수
  float hum = dht.readHumidity();             // 습도 값을 hum 변수에 저장
  float temp = dht.readTemperature();         // 온도 값을 temp 변수에 저장

  float discomfort_index = ((9 * temp) / 5) - ((0.55 * (1 - (hum / 100))) * (((9 * temp) / 5) - 26)) + 32; //불쾌지수 계산식

  Serial.print("temp : "); Serial.print((int)temp); Serial.print(" *C, ");
  Serial.print("hum : "); Serial.print((int)hum); Serial.print(" %, ");
  Serial.print("discomfort_index : "); Serial.println((int)discomfort_index);

  if(stack == 10){
    char num1 = String((int)temp).charAt(0);
    char num2 = String((int)temp).charAt(1);
    char text[3] = {num1, num2, 13};
    stack = 0;
    bluetooth.write(text);
  }
  
  if (angle == init_angle) {
    lcd.setCursor(0, 0);                                           // 커서 1번 칸, 1번 줄로 이동
    lcd.print("T : "); lcd.print((int)temp); lcd.print("C, ");     // int 형으로 LCD에 온도 출력
    lcd.print("H : "); lcd.print((int)hum); lcd.print("%");        // int 형으로 LCD에 습도 출력
    lcd.setCursor(0, 1);                                           // 커서 1번 칸, 2번 줄로 이동
    lcd.print("Discomfort : "); lcd.print((int)discomfort_index);  // int 형으로 LCD에 불쾌지수 출력
  }
  if ((int)discomfort_index > 80) {           // 만약 불쾌지수가가 75보다 높다면?
    analogWrite(fan, 255);                     // fan 동작
    Smart_light(255, 000, 000);                // 스마트 전등 빨간색 출력
  }
  else {
    analogWrite(fan, fan_speeds);              // fan 동작
  }
  stack++;
}
