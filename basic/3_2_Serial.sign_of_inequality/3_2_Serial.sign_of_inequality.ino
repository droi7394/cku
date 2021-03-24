int a; // "a" 라는 이름의 변수(저장공간)
int b; // "b" 라는 이름의 변수(저장공간)
void setup() {
Serial.begin(9600);
 a= 7; // a 공간에 5를 저장 " = " 은 대입 연산자 (저장 연산자)
 b= -5; // b 공간에 -5를 저장

Serial.println(a==b); // 출력 = ??
Serial.println(a>b); // 출력 = ??
Serial.println(a<b); // 출력 = ??
Serial.println(a>0); // 출력 = ??
Serial.println(a<0); // 출력 = ??

}

void loop() {

}
