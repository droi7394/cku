int  Led_pin = 9;  //변수 Led_pin을 9로 선언
int Analog_pin = A5; // 변수 Analog_pin을 A5로 선언

void setup() {
  Serial.begin(9600);    //시리얼 통신 초기화
  pinMode(Led_pin, OUTPUT);
}

void loop() {
  int val = analogRead(Analog_pin);  //가변저항 값을 val에 저장
  val = map(val, 0, 1023, 0, 255);   //val 값의 범위를 변화
  analogWrite(Led_pin, val);
}
