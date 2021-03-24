#include "DHT.h"
#define DHTPIN 8                           // DHT11 디지털 입력 핀을 8번 핀으로 설정
#define DHTTYPE DHT11                      // DHT11 모듈 사용 선언

DHT dht(DHTPIN,DHTTYPE);                   // DHT 클래스 함수 선언
int fan = 11;                              // Fan을 11핀으로 선언
int fan_speed = 0;                         // Fan 속도를 저장하기 위한 변수 선언

void setup() {
  Serial.begin(9600);                      //PC와 아두이노간 시리얼 통신 속도를 9600bps로 설정 
  dht.begin();                             //DHT 모듈 초기화
  pinMode(fan,OUTPUT);                     //fan 핀 모드를 출력으로 설정
}

void loop() {
 int DI = DHT_11();                        // DHT_11함수 호출, 리턴 값 DI에 저장
 if(DI > 80){                              // 만약 DI(불쾌지수)가 80보다 높다면? 
   analogWrite(fan,255);                   // fan 동작
 }
 else{
   analogWrite(fan,0);                     // fan 동작정지  
  }
  
 delay(100);
}
int DHT_11(){                                                                         // 온습도 센서의 값과 불쾌지수 값을 출력하는 함수
  float hum = dht.readHumidity();                                                     // 습도 값을 hum 변수에 저장
  float temp = dht.readTemperature();                                                 // 온도 값을 temp 변수에 저장
  float discomfort_index = ((9*temp)/5)-((0.55*(1-(hum/100)))*(((9*temp)/5)-26))+32;  //불쾌지수 계산식
  Serial.print("temp : "); Serial.print((int)temp); Serial.print(" *C, "); 
  Serial.print("hum : "); Serial.print((int)hum); Serial.print(" %, ");
  Serial.print("discomfort_index : "); Serial.println((int)discomfort_index);
  return (int)discomfort_index; //불쾌지수를 출력.
}
