/* 이 소스는 에듀이노(Eduino)에 의해서 번역, 수정, 작성되었고 소유권 또한 에듀이노의 것입니다. 
 *  소유권자의 허락을 받지 않고 무단으로 수정, 삭제하여 배포할 시 법적인 처벌을 받을 수도 있습니다. 
 *  
 *  에듀이노 SmartCar 예제
 *  - 스마트 자동차 스스로 눈앞에 장애물을 회피하며 움직이는 예제 -
 *   
 */
#include <Servo.h>
Servo EduServo;

//출력핀(trig)과 입력핀(echo) 설정
int trigPin = 13;                  // 디지털 13번 핀에 연결
int echoPin = 12;                  // 디지털 12번 핀에 연결
int Ultra_d = 0;

   
int RightMotor_E_pin = 5;       // 오른쪽 모터의 Enable & PWM
int LeftMotor_E_pin = 6;        // 왼쪽 모터의 Enable & PWM
int RightMotor_1_pin = 8;       // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;       // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;       // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;       // 왼쪽 모터 제어선 IN4

int motor_s = 160;              // 최대 속도(0~255)의 60% 
int val = 0;

void setup() {  
  EduServo.attach(2);                       // 서보모터 PWM 디지털입출력 2번핀 연결
  
  pinMode(echoPin, INPUT);                  // echoPin 입력
  pinMode(trigPin, OUTPUT);                 // trigPin 출력
  
  pinMode(RightMotor_E_pin, OUTPUT);        // 출력모드로 설정
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);

  Serial.begin(9600);                       // PC와의 시리얼 통신 9600bps로 설정
  Serial.println("Welcome Eduino!");
}

void loop() { 
  Ultra_d = Ultrasonic();
  Serial.println(Ultra_d);
  motor_role(HIGH, HIGH, motor_s);  // 직진

  if(Ultra_d < 250) {
    if (Ultra_d < 150) {
      Serial.println("150 이하.");
      motor_role(LOW, LOW, motor_s); // 후진
      delay(1000);
      motor_role(HIGH, HIGH, 0);  // 정지
      delay(200);
    }
    else {
      motor_role(HIGH, HIGH, 0);  // 정지
      delay(200);
      Serial.println("150 이상.");
      val =  Servo_con();
      if (val == 0) {
        Serial.println("우회전.");
        motor_role(HIGH, HIGH, 0);  // 정지
        delay(500);
        motor_role(LOW, LOW, motor_s);  // 후진
        delay(500);
        motor_role(LOW, HIGH, motor_s);  // 우회전
        delay(800);
      }
      else if (val == 1) {
        Serial.println("좌회전.");
        motor_role(HIGH, HIGH, 0);  // 정지
        delay(500);
        motor_role(LOW, LOW, motor_s);  // 후진
        delay(500);
        motor_role(HIGH, LOW, motor_s);  // 좌회전
        delay(800);
      }
    }
  }
}

void motor_role(int R_motor, int L_motor, int Speed){
   digitalWrite(RightMotor_1_pin, R_motor);
   digitalWrite(RightMotor_2_pin, !R_motor);
   digitalWrite(LeftMotor_3_pin, L_motor);
   digitalWrite(LeftMotor_4_pin, !L_motor);
   
   analogWrite(RightMotor_E_pin, Speed);  // 우측 모터 속도값
   analogWrite(LeftMotor_E_pin, Speed);   // 좌측 모터 속도값  
}

int Ultrasonic(){
  long duration, distance;
  digitalWrite(trigPin, HIGH);      // trigPin에서 초음파 발생(echoPin도 HIGH)        
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);   // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  distance = ((float)(340 * duration) / 1000) / 2; 

  //Serial.print("DIstance:");        // 물체와 초음파 센서간 거리를 표시.        
  //Serial.println(distance);

  return distance;
}

int Servo_con(){
  EduServo.write(30);
  int Ult_30 = Ultrasonic();
  delay(1000);
  EduServo.write(150);
  int Ult_150 = Ultrasonic();
  delay(1000);

  if(Ult_30 > Ult_150){
     val = 1;
  }
  else{
     val = 0;
  }
  EduServo.write(90);
   
  return val;
}
