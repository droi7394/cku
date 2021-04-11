int RightMotor_E_pin = 5;      // 오른쪽 모터의 Enable & PWM test
int RightMotor_1_pin = 8;      // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;     // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;      // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;      // 왼쪽 모터 제어선 IN4
int LeftMotor_E_pin = 6;      // 왼쪽 모터의 Enable & PWM

void SmartCar_Go();
void SmartCar_Back();


int E_carSpeed = 153; // 최대 속도의  60 %, 범위 (0~255)

void setup() {
  pinMode(RightMotor_E_pin, OUTPUT);        // 출력모드로 설정
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);
}

void loop() {
  SmartCar_Go();
  delay(3000);
  SmartCar_Back();
  delay(3000);
}


void SmartCar_Go() {       // 전진
  Serial.println("Forward");
  digitalWrite(RightMotor_1_pin, HIGH);  // 우측앞바퀴 - 정회전
  digitalWrite(RightMotor_2_pin, LOW);   // 우측 뒷바퀴 - 정회전
  digitalWrite(LeftMotor_3_pin, HIGH);   // 좌측 앞바퀴 -정회전
  digitalWrite(LeftMotor_4_pin, LOW);    // 좌측뒷바퀴  - 정회전

  for (int i = 0; i <= E_carSpeed; i = i + 5) {  // 제한된 최고속도까지 5씩 속도를 증가시킨다.
    analogWrite(RightMotor_E_pin, i);            // 우측바퀴 속도 제어
    analogWrite(LeftMotor_E_pin, i);             // 좌측바퀴 속도 제어
    delay(20);
  }
}

void SmartCar_Back() {       // 후진
  Serial.println("Backward");
  digitalWrite(RightMotor_1_pin, LOW);   // 역회전
  digitalWrite(RightMotor_2_pin, HIGH);  // 역회전
  digitalWrite(LeftMotor_3_pin, LOW);    // 역회전
  digitalWrite(LeftMotor_4_pin, HIGH);   // 역회전

  for (int i = 0; i <= E_carSpeed; i = i + 5) {
    analogWrite(RightMotor_E_pin, i);     
    analogWrite(LeftMotor_E_pin, i);
    delay(20);
  }
}
