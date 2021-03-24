/* 이 소스는 에듀이노(Eduino)에 의해서 번역, 수정, 작성되었고 소유권 또한 에듀이노의 것입니다. 
 *  소유권자의 허락을 받지 않고 무단으로 수정, 삭제하여 배포할 시 법적인 처벌을 받을 수도 있습니다. 
 *  
 *  에듀이노 SmartCar 기본예제 4
 *  - 스마트 자동차 전진, 후진, 좌회전, 우회전, 정지 명령 적외선 리모컨으로 제어하기 -
 *  
 *  적외선 수신센서를 연결한 상태에서 적외선 리모컨으로 명령하여 
 *  스마트 자동차의 동작을 제어하는 예제입니다.
 *  
 *  명령
 *  1. 적외선 리모컨의 +
 *  -> 모터 속도 증가
 *  2. 적외선 리모컨의 -
 *  -> 모터 속도 감소
 *  3. 적외선 리모컨의 2
 *  -> 전진 명령
 *  4. 적외선 리모컨의 5
 *  -> 정지 명령
 *  5. 적외선 리모컨의 8
 *  -> 후진 명령
 *  6. 적외선 리모컨의 2
 *  -> 전진 명령
 *  7. 적외선 리모컨의 4
 *  -> 좌회전 명령
 *  8. 적외선 리모컨의 6
 *  -> 우회전 명령
 *  
 */

 /*
 * IR remote 이름과 주소 
 *  이름,  16진수 주소 , 10진수 주소
  { "0",    0xFF6897 , 16738455 } 
  { "1",    0xFF30CF , 16724175 }
  { "2",    0xFF18E7 , 16718055 }
  { "3",    0xFF7A85 , 16743045 }
  { "4",    0xFF10EF , 16716015 }
  { "5",    0xFF38C7 , 16726215 }
  { "6",    0xFF5AA5 , 16734885 }
  { "7",    0xFF42BD , 16728765 }
  { "8",    0xFF4AB5 , 16730805 }
  { "9",    0xFF52AD , 16732845 }
  { "100+", 0xFF9867 , 16750695 }
  { "200+", 0xFFB04F , 16756815 }
  { "-",    0xFFE01F , 16769055 }
  { "+",    0xFFA857 , 16754775 }
  { "EQ",   0xFF906F , 16748655 }
  { "<<",   0xFF22DD , 16720605 }
  { ">>",   0xFF02FD , 16712445 }
  { ">|",   0xFFC23D , 16761405 }
  { "CH-",  0xFFA25D , 16753245 }
  { "CH",   0xFF629D , 16736925 }
  { "CH+",  0xFFE21D , 16769565 }
*/

#include <IRremote.h>
int RECV_PIN = A0;              // 적외선 수신센서 핀(아날로그 입력 A0)
IRrecv irrecv(RECV_PIN);        // 적외선 송수신 통신을 위한 객체
decode_results IR_Signal;       // 적외선 수신값 해석을 위한 객체

int RightMotor_E_pin = 5;       // 오른쪽 모터의 Enable & PWM
int LeftMotor_E_pin = 6;        // 왼쪽 모터의 Enable & PWM
int RightMotor_1_pin = 8;       // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;       // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;       // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;       // 왼쪽 모터 제어선 IN4

int motor_s = 153;              // 최대 속도(0~255)의 60% 

int R_Motor = 0;
int L_Motor = 0;
int mode = 0;

void setup() {
  pinMode(RightMotor_E_pin, OUTPUT);        // 출력모드로 설정
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);

  Serial.begin(9600);                       // PC와의 시리얼 통신 9600bps로 설정
  Serial.println("Welcome Eduino!");
  
  irrecv.enableIRIn(); // 적외선 통신 수신 시작
}

void loop() { 
  if(irrecv.decode(&IR_Signal)){      // 적외선(IR) 수신값이 있는지 판단.
       
    Serial.print("Input Signal : ");
    Serial.print("HEX[ "); Serial.print(IR_Signal.value, HEX); Serial.print(" ], ");
    Serial.print("Int[ "); Serial.print((String)IR_Signal.value); Serial.print(" ] || ");
    
    control_SmartCar((String)IR_Signal.value);

    if(mode == 0){
      motor_role(R_Motor, L_Motor, motor_s);
    }
    else if(mode == 1){
      Right_role(R_Motor, L_Motor, motor_s);
    }
    else if(mode == 2){
      Left_role(R_Motor, L_Motor, motor_s);
    }
    else{
      motor_role(R_Motor, L_Motor, 0);
    }
    
    irrecv.resume();  // 다음 적외선 값 수신   
  } 
}

void control_SmartCar(String Remote_Val){ 
  if( Remote_Val == "16754775" ){      // "+" 버튼, 명령 : 속도 증가
    motor_s = motor_s + 20;
    motor_s = min(motor_s, 255);
    Serial.print("Speed Up : "); 
  }
  
  else if( Remote_Val == "16769055" ){ // "-" 버튼, 명령 : 속도 감소
    motor_s = motor_s - 20;
    motor_s = max(motor_s, 50);
    Serial.print("Speed Down : ");
  }
  
  else if(Remote_Val == "16718055" ){  // "2" 버튼, 명령 : 전진
    R_Motor = HIGH; L_Motor = HIGH; mode = 0;
    Serial.print("Forward : ");
  }  
  
  else if( Remote_Val == "16716015" ){ // "4" 버튼, 명령 : 좌회전
    mode = 2;
    Serial.print("Turn Left : "); 
  }
  
  else if( Remote_Val == "16734885" ){ // "6" 버튼, 명령 : 우회전
    mode = 1;
    Serial.print("Turn Right : "); 
  }
  
  else if( Remote_Val == "16730805" ){ // "8" 버튼, 명령 : 후진
    R_Motor = LOW; L_Motor = LOW; mode = 0;
    Serial.print("Backward : "); 
  }

  else if( Remote_Val == "16726215" ){ // "5" 버튼, 명령 : 정지
    mode = 3;
    Serial.print("Stop : ");  
  }
  
  else{
    Serial.print("Not Defined : ");  // 지정하지 않은 주소입력.
  }
  
  Serial.print("R_Motor[ ");Serial.print(R_Motor);Serial.print(" ], ");
  Serial.print("L_Motor[ ");Serial.print(L_Motor);Serial.print(" ], ");
  Serial.print("motor_s[ ");Serial.print(motor_s);Serial.print(" ], ");
  Serial.print("Mode[ ");Serial.print(mode);Serial.println(" ]");
}

void motor_role(int R_motor, int L_motor, int Speed){
   digitalWrite(RightMotor_1_pin, R_motor);
   digitalWrite(RightMotor_2_pin, !R_motor);
   digitalWrite(LeftMotor_3_pin, L_motor);
   digitalWrite(LeftMotor_4_pin, !L_motor);
   
   analogWrite(RightMotor_E_pin, Speed);  // 우측 모터 속도값
   analogWrite(LeftMotor_E_pin, Speed);   // 좌측 모터 속도값  
}

void Right_role(int R_motor, int L_motor, int Speed){
   digitalWrite(RightMotor_1_pin, R_motor);
   digitalWrite(RightMotor_2_pin, !R_motor);
   digitalWrite(LeftMotor_3_pin, L_motor);
   digitalWrite(LeftMotor_4_pin, !L_motor);
   
   analogWrite(RightMotor_E_pin, max(Speed*0.4,50));  // 우측 모터 속도값
   analogWrite(LeftMotor_E_pin, min(Speed*1.4,255));   // 좌측 모터 속도값
}

void Left_role(int R_motor, int L_motor, int Speed){
   digitalWrite(RightMotor_1_pin, R_motor);
   digitalWrite(RightMotor_2_pin, !R_motor);
   digitalWrite(LeftMotor_3_pin, L_motor);
   digitalWrite(LeftMotor_4_pin, !L_motor);
   
   analogWrite(RightMotor_E_pin, min(Speed*1.4,255));  // 우측 모터 속도값
   analogWrite(LeftMotor_E_pin, max(Speed*0.2,50));   // 좌측 모터 속도값   
}
