int RightMotor_E_pin = 5;      // 오른쪽 모터의 Enable & PWM
int RightMotor_1_pin = 8;      // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;     // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;      // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;      // 왼쪽 모터 제어선 IN4
int LeftMotor_E_pin = 6;      // 왼쪽 모터의 Enable & PWM

void SmartCar_Go();
void SmartCar_Back();


int E_carSpeed = 153; // 최대 속도의  60 %

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
  digitalWrite(RightMotor_1_pin, HIGH);
  digitalWrite(RightMotor_2_pin, LOW);
  digitalWrite(LeftMotor_3_pin, HIGH);
  digitalWrite(LeftMotor_4_pin, LOW);

  for (int i = 0; i <= E_carSpeed; i = i + 5) {
    analogWrite(RightMotor_E_pin, i);     
    analogWrite(LeftMotor_E_pin, i);
    delay(20);
  }
}

void SmartCar_Back() {       // 후진
  Serial.println("Backward");
  digitalWrite(RightMotor_1_pin, LOW);
  digitalWrite(RightMotor_2_pin, HIGH);
  digitalWrite(LeftMotor_3_pin, LOW);
  digitalWrite(LeftMotor_4_pin, HIGH);

  for (int i = 0; i <= E_carSpeed; i = i + 5) {
    analogWrite(RightMotor_E_pin, i);     
    analogWrite(LeftMotor_E_pin, i);
    delay(20);
  }
}
