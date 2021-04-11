#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(2);
}

void loop() {
  myservo.write(0);   // 서보모터 각도 0 도
  delay(3000);        // 3초 대기
  myservo.write(90);  // 서보모터 각도 90도
  delay(3000);        // 3초 대기
  myservo.write(180); // 서보모터 각도 180 도
  delay(3000);        // 3초 대기
  myservo.write(90);  // 서보모터 각도 90도
  delay(3000);
} 
