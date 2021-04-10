/*  L298N 모터 모듈을 활용한 초음파 센서 제어 회로 */
int distance;
int triggerPin = 13;
int echoPin = 12;
int LED = 7;               // 뉴트라이

#define IN1 8  // L298모듈의 제어 신호 입력 핀 번호 지정

void forward() {      // L298 제어용 전진 함수
  digitalWrite(IN1, HIGH);  // 오른쪽앞바퀴
}

/*
void back() {         // 후진
  digitalWrite(IN1, LOW);   // 오른쪽앞바퀴
}

void left() {         // 좌회전(왼쪽모터 멈춤:오른쪽모터 전진)
  digitalWrite(IN1, LOW);    // 오른쪽앞바퀴
}

void right() {      // 우회전(왼쪽모터 전진:오른쪽모터 멈춤)
  digitalWrite(IN1, HIGH);   // 오른쪽앞바퀴
}
*/

void stop() {       // 정지
  digitalWrite(IN1, LOW);    // 오른쪽앞바퀴
  pinMode(LED, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);      // 트리거 핀을 출력으로 설정 , 초음파 보내기
  pinMode(echoPin, INPUT);          // 에코 핀을 입력으로 설정   , 초음파 받기
  pinMode(LED, OUTPUT);               // 뉴트라이
}

void loop() {
  digitalWrite(triggerPin, HIGH);    // 트리거핀으로 10us의 펄스 발생
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  distance = pulseIn(echoPin, HIGH)/58;     //에코 핀의 값을 cm 단위로 계산
  distance = distance > 100 ? 100 : distance; // 100cm 이상은 모두 100cm로 처리
  Serial.println("Distance(cm) = " + String(distance));
  if (distance > 50) {       // 50cm 이내 장애물 감지
    stop();
//  delay(500);
    digitalWrite(LED, LOW);               // 뉴트라이
//  delay(500);               // 뉴트라이

  } else {                     // 50cm이내에 벽이 없다면 전진
    forward();
    digitalWrite(LED, HIGH);                // 뉴트라이
//  delay(500);  

 }
}
