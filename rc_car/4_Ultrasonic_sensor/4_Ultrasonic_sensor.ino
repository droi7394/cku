int trigPin = 13;
int echoPin = 12;

void setup() {
  Serial.begin(9600);       // 시리얼 속도 설정
  pinMode(echoPin, INPUT);   // echoPin 입력
  pinMode(trigPin, OUTPUT);  // trigPin 출력
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);                        // trigPin에서 초음파 발생(echoPin도 HIGH)
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);                  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  distance = ((float)(340 * duration) / 1000) / 2; 
  Serial.print("distance:");                          // 물체와 초음파 센서간 거리를 표시
  Serial.print(distance);
  Serial.println(" mm");
  delay(500);
}
