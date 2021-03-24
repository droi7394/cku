void setup() {
 pinMode(5,INPUT_PULLUP); // 5번 핀의 모드를 INPUT_PULLUP 상태로 설정합니다.
 Serial.begin(9600); // 시리얼 통신 초기화 
}

void loop() {
  int d_sig = digitalRead(5); // 5번 핀으로 입력 받은 값을 d_sig에 대입
  Serial.print("스위치로 입력받은 디지털 신호 :"); // 문장 출력
  delay(50);
}
