int led = 3;  // LED를 3번핀으로 선언합니다.
int sw = 5;   // 스위치를 5번핀으로 선언합니다.

void setup() {
  pinMode(led, OUTPUT);//LED 핀을 OUTPUT으로 설정합니다.
  pinMode(sw, INPUT_PULLUP);//스위치가 연결된 핀의 모드를 INPUT_PULLUP 상태로 설정합니다.

}

void loop() {
  if (digitalRead(sw) = LOW) { // 스위치가 연결된 핀의 로직레벨이 LOW라면, LED가 켜지도록 합니다.
    digitalWrite(led, HIGH); // 3번 핀으로 HIGH(5V)출력
  }
  else {
    digitalWrite(led, LOW);
  }
}
