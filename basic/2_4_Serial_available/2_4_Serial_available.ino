int a; // "a" 라는 이름의 변수(저장공간)
int b; // "b" 라는 이름의 변수(저장공간)
int c; // "c" 라는 이름의 변수(저장공간)
void setup() {
Serial.begin(9600);
 a= 7; // a 공간에 5를 저장 " = " 은 대입 연산자 (저장 연산자)
 b= -5; // b 공간에 -5를 저장
 c= a+b; // ab 공간에 a(7) + b(-5)를 더하기한 값을 저장

Serial.println("ab"); // "ab" 문자를 출력
Serial.println(ab); // ab 공간의 값을 출력
Serial.println(a-b); // 출력 = ??
Serial.println(a*b); // 출력 = ??
Serial.println(a/b); // 출력 = ??

}

void loop() {

}
