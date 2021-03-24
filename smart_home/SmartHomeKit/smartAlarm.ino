//****************** 침입자 경보시스템 함수 ******************//
//침입자 경보시스템은 강제로 무한루프에 빠뜨려 다른 기능을 먹통으로 만듬.//
void Smart_Alarm() {
  while (1) {
    Serial.println("경비시스템 작동중!!");
    lcd.setCursor(0, 0); lcd.print("Security system ");
    lcd.setCursor(0, 1); lcd.print(" IRsenser off   ");

    Smart_light(000, 000, 000);               // 스마트 전등 "OFF"
    if (digitalRead(IRPin) == LOW) {          // 스위치 동작 확인
      Serial.println("경비시스템 침입자 발생!!!");
      lcd.setCursor(0, 0); lcd.print("!!!emergency!!! ");
      lcd.setCursor(0, 1); lcd.print(" IRsenser on    ");

      for (int i = 0; i < 2; i++) {           // for 반복문을 활용하여 i값을 0~2까지 반복
        tone(piezo, tones[i]);                // piezo핀에 tones에 저장된 주파수를 출력
        Smart_light(000, 000, 255);           // 스마트 전등 파란색 출력
        delay(600);                           // 출력마다 0.3초의 딜레이
        Smart_light(255, 000, 000);           // 스마트 전등 빨간색 출력
        delay(600);                           // 출력마다 0.3초의 딜레이
      }
      noTone(piezo);                          // piezo핀 초기화.
    }
    if (bluetooth.available()) {              // 만약 블루투스로부터 받은 통신이 있다면,
      if (bluetooth.find("CapsOFF")) {        // 문자 "CapsOFF"를 검색
        Smart_light(000, 000, 000);           // 스마트 전등 "OFF"
        Caps = 0;
        break;                                // 경보시스템의 무한루프 종료.
      }
    }
    if (Serial.available()) {              // 만약 시리얼로부터 받은 통신이 있다면,
      if (Serial.find("CapsOFF")) {        // 문자 "CapsOFF"를 검색
        Smart_light(000, 000, 000);           // 스마트 전등 "OFF"
        Caps = 0;
        break;                                // 경보시스템의 무한루프 종료.
      }
    }
    delay(10);
  }
}
