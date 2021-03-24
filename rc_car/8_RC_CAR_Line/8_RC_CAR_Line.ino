/* 이 소스는 에듀이노(Eduino)에 의해서 번역, 수정, 작성되었고 소유권 또한 에듀이노의 것입니다.
    소유권자의 허락을 받지 않고 무단으로 수정, 삭제하여 배포할 시 법적인 처벌을 받을 수도 있습니다.

    에듀이노 SmartCar 예제
    - 스마트 자동차 검정색 라인을 따라 스스로 움직이는 예제 -

*/

int RightMotor_E_pin = 5;      // 오른쪽 모터의 Enable & PWM
int LeftMotor_E_pin = 6;       // 왼쪽 모터의 Enable & PWM
int RightMotor_1_pin = 8;      // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;      // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;      // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;      // 왼쪽 모터 제어선 IN4

int L_Line = A5; // 왼쪽 라인트레이서 센서는 A3 핀에 연결
int C_Line = A4; // 가운데 라인트레이서 센서는 A4 핀에 연결
int R_Line = A3; // 오른쪽 라인트레이서 센서는 A5 핀에 연결

int motor_s = 120;     // 모터 속도 최대 255

int SL = 1;
int SC = 1;
int SR = 1;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(RightMotor_E_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);

  Serial.begin(9600);    // PC와의 시리얼 통신 9600bps로 설정
  Serial.println("Welcome Eduino!");
}

void loop() {
  int L = digitalRead(L_Line);
  int C = digitalRead(C_Line);
  int R = digitalRead(R_Line);

  Serial.print("digital : "); Serial.print(L); Serial.print(", "); Serial.print(C); Serial.print(", "); Serial.print(R); Serial.print("   ");

  if ( L == LOW && C == LOW && R == LOW ) {   // 0 0 0
    L = SL; C = SC; R = SR;
  }
  else if ( L == HIGH && C == LOW && R == HIGH ) {   // 0 0 0
    L = SL; C = SC; R = SR;
  }

  
  if ( L == 1 && C == 1 && R == 1 ) {  // 0 1 0
    motor_role(HIGH, HIGH, motor_s);
    Serial.println("직진");
  }
  else if ( L == 0 && C == 1 && R == 0 ) {  // 0 1 0
    motor_role(HIGH, HIGH, motor_s);
    Serial.println("직진");
  }
  else if (L == 0 && C == 1 && R == 1 ){   // 0 1 1
    motor_role(HIGH, HIGH, motor_s);
    Serial.println("우회전");
  }
  else if ( L == 0 && C == 0 && R == 1 ) {         // , 0 0 1
    Right_role(LOW, HIGH, motor_s);
    Serial.println("우회전");
  }
  else if (L == 1 && C == 1 && R == 0 ){     // 1 1 0, 
    motor_role(HIGH, HIGH, motor_s);
    Serial.println("좌회전");
  }
  else if (  L == 1 && C == 0 && R == 0 ) {         // 1 0 0
    Left_role(HIGH, LOW, motor_s);
    Serial.println("좌회전");

  }
  else if ( L == 0 && C == 0 && R == 0 ) {       // 1 1 1, 1 0 1
    motor_role(HIGH, HIGH, 0);
    Serial.println("정지");
  }
  

  SL = L; SC = C; SR = R;

}

void motor_role(int R_motor, int L_motor, int Speed) {
  digitalWrite(RightMotor_1_pin, R_motor);
  digitalWrite(RightMotor_2_pin, !R_motor);
  digitalWrite(LeftMotor_3_pin, L_motor);
  digitalWrite(LeftMotor_4_pin, !L_motor);

  analogWrite(RightMotor_E_pin, Speed);  // 우측 모터 속도값
  analogWrite(LeftMotor_E_pin, Speed);   // 좌측 모터 속도값
}

void Right_role(int R_motor, int L_motor, int Speed) {
  digitalWrite(RightMotor_1_pin, R_motor);
  digitalWrite(RightMotor_2_pin, !R_motor);
  digitalWrite(LeftMotor_3_pin, L_motor);
  digitalWrite(LeftMotor_4_pin, !L_motor);

  analogWrite(RightMotor_E_pin, max(Speed * 0.4, 50)); // 우측 모터 속도값
  analogWrite(LeftMotor_E_pin, min(Speed * 1.4, 255)); // 좌측 모터 속도값
}
void Left_role(int R_motor, int L_motor, int Speed) {
  digitalWrite(RightMotor_1_pin, R_motor);
  digitalWrite(RightMotor_2_pin, !R_motor);
  digitalWrite(LeftMotor_3_pin, L_motor);
  digitalWrite(LeftMotor_4_pin, !L_motor);

  analogWrite(RightMotor_E_pin, min(Speed * 1.4, 255)); // 우측 모터 속도값
  analogWrite(LeftMotor_E_pin, max(Speed * 0.2, 50)); // 좌측 모터 속도값
}
