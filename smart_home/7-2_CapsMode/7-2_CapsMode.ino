#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);                     // 0x27 or 0x3F

int piezo = 7;                                          //피에조 부저를 3번 핀에 연결하기 위한 변수 선언
int tones[] = {261, 523};                               // tones[] 배열에 원하는 음역대의 주파수를 저장.
int IRPin = 10;                                         // IRPin을 6로 선언합니다

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);                                   //PC와 아두이노간 시리얼 통신 속도를 9600bps로 설정
  pinMode(piezo, OUTPUT);                               // 피에조 핀 출력으로 설정
  pinMode(IRPin, INPUT);                                // IRPin을 입력으로 설정합니다.
}

void loop() {
  if (digitalRead(IRPin) == LOW) {                          // 스위치 동작 확인
    for (int i = 0; i < 2; i++) {                           // for 반복문을 활용하여 i값을 0~2까지 반복
      tone(piezo, tones[i]);                                // piezo핀에 tones에 저장된 주파수를 출력
      delay(500);                                           // 출력마다 0.5초의 딜레이를 준다.
      lcd.setCursor(0, 0); lcd.print(" !!emergency!! ");
      lcd.setCursor(0, 1); lcd.print("  IRsensor on   ");
    }
  }
  else {
    noTone(piezo);  // piezo핀 초기화.
    lcd.setCursor(0, 0); lcd.print("Security system ");
    lcd.setCursor(0, 1); lcd.print("  IRsensor off  ");
  }
  delay(100);
}
