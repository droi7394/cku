/* 이 소스는 에듀이노(Eduino)에 의해서 번역, 수정, 작성되었고 소유권 또한 에듀이노의 것입니다. 
 *  소유권자의 허락을 받지 않고 무단으로 수정, 삭제하여 배포할 시 법적인 처벌을 받을 수도 있습니다. 
 *  
 *  에듀이노 SmartCar 예제
 *  - 스마트 자동차 전진, 후진, 정지 명령 시리얼통신으로 제어하기 -
 *  
 *  PC와 USB케이블을 우노 보드와 연결한 상태에서 
 *  터미널을 통해 키보드 명령을 하면 스마트 자동차가 움직이는 예제.
 *  
 *  명령
 *  1. 터미널에 키보드로 g 라고 입력함
 *  -> 스마트 카 전진
 *  2. 터미널에 키보드로 b 라고 입력함
 *  -> 스마트 카 후진
 *  3. 터미널에 키보드로 s 라고 입력함
 *  -> 스마트 카 정지
 *  
 */

int RightMotor_E_pin = 5;      // 오른쪽 모터의 Enable & PWM
int LeftMotor_E_pin = 6;       // 왼쪽 모터의 Enable & PWM
int RightMotor_1_pin = 8;      // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;      // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;      // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;      // 왼쪽 모터 제어선 IN4

int motor_s  = 153;          // 최대 속도(0~255)의 60% 

void setup() {
  pinMode(RightMotor_E_pin, OUTPUT);       // 출력모드로 설정
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);

  Serial.begin(9600);                       
  Serial.println("Welcome Eduino!");
}

void loop() {
  if (Serial.available()){                  
    char command = Serial.read();          
    Serial.print("Recived command : ");
    if(command == 'g'){                    
      motor_role(HIGH, HIGH, motor_s);
      Serial.println("직진"); 
    }
    else if(command == 'b'){               
      motor_role(LOW, LOW, motor_s); 
      Serial.println("후진"); 
    }
    else if(command == 's'){               
      motor_role(HIGH, HIGH, 0); 
      Serial.println("정지"); 
    }
    else{
      Serial.println("Wrong command");      
    }
  }
}

void motor_role(int R_motor, int L_motor, int Speed){
   digitalWrite(RightMotor_1_pin, R_motor);
   digitalWrite(RightMotor_2_pin, !R_motor);
   digitalWrite(LeftMotor_3_pin, L_motor);
   digitalWrite(LeftMotor_4_pin, !L_motor);
   
   analogWrite(RightMotor_E_pin, Speed);  
   analogWrite(LeftMotor_E_pin, Speed);    
}
