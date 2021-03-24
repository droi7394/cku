
int Analog_pin = A5; // 변수 Analog_pin을 A5로 선언

void setup() {
  Serial.begin(9600);    //시리얼 통신 초기화
}

void loop() {
  int val = analogRead(Analog_pin);  //가변저항 값을 val에 저장
  Serial.println(val);

}
