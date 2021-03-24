int Sensor = 10 ;                          // 센서핀은 10번에 연결
int val ;
void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);                 // 센서값을 입력으로 설정
}

void loop() {
  val = digitalRead(Sensor);              // 센서값 읽어옴

  if(val == 0){
    Serial.println("STOP!!");
    }
  else{
    Serial.println("Nothing");
    }
}
