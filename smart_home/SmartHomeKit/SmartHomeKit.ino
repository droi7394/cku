//****************** bluetooth 선언 ******************//
#include <SoftwareSerial.h>                   // 가상 시리얼 통신을 위한 라이브러리 선언
#define BT_RXD 5                              // 아두이노의 5번 핀을 RX핀 지정! 블루투스와 TX핀 연결
#define BT_TXD 4                              // 아두이노의 4번 핀을 TX핀 지정! 블루투스의 RX핀 연결
SoftwareSerial bluetooth(BT_RXD, BT_TXD);     // 블루투스 통신을 위한 설정

//****************** LCD I2C 선언 ******************//
#include <Wire.h>                             // I2C 통신을 위한 라이브러리 
#include <LiquidCrystal_I2C.h>                // LCD 1602 I2C용 라이브러리 
LiquidCrystal_I2C lcd(0x27, 16, 2);           // 접근 주소 : 0x3F or 0x27

//****************** 스마트 전등 선언 ******************//
#include <Adafruit_NeoPixel.h>                // RGB_LED 사용을 위한 라이브러리 선언
Adafruit_NeoPixel RGB_LED = Adafruit_NeoPixel(3, 6, NEO_GRB); // 3개의 LED와 제어핀을 6번 핀으로 설정.
int R_Val, G_Val, B_Val = 0;                  // RGB_LED의 led 색상값을 저장하기 위한 변수

//****************** 스마트 에어콘 선언 ******************//
#include "DHT.h"
#define DHTPIN 8                              // DHT11 디지털 입력 핀을 8번 핀으로 설정
#define DHTTYPE DHT11                         // DHT11 모듈 사용 선언
DHT dht(DHTPIN, DHTTYPE);                     // DHT 클래스 함수 선언
int fan = 11;                                 // Fan을 11번 핀으로 선언
int fan_speed = 0;                            // Fan 속도를 저장하기 위한 변수 선언
int stack = 0;                                // 전송 속도를 조절해주기 위한 변수 선언

//****************** 스마트 도어 선언 ******************//
#include <Servo.h>                            // 서보 라이브러리를 사용하기 위한 Servo.h 선언
Servo servo;                                  // 서보 클래스 타입인 servo 객체 선언
int servo_pin = 13;                           // 서보의 제어핀 13번 핀으로 선언
int init_angle = 180;                         // 서보의 각도 초기값
int angle = init_angle;                       // 서보의 각도를 저장하기 위한 변수
int control_num = 0;                          // 도어락의 상태를 저장하기 위한 변수

//****************** 침입자 감지 선언 ******************//
int piezo = 7;                                // 피에조 부저를 7번 핀으로 선언
int tones[] = {261, 523};                     // tones[] 배열에 원하는 음역대의 주파수를 저장.
int IRPin = 10;                               // 적외선 센서를 10번 핀으로 선언
int Caps = 0; 

// Smart Home SetUp
void setup() {
  Serial.begin(9600);                         // PC와 아두이노간 시리얼 통신 속도를 9600bps로 설정
  bluetooth.begin(9600);                      // 블루투스와 아두이노간 시리얼 통신 속도를 9600bps로 설정
  lcd.init();                                 // LCD 모듈 초기화
  lcd.backlight();                            // LCD 모듈 백라이트 켜기

  //********* 스마트 전등 Setup() *********//
  RGB_LED.begin();                            // LED 모듈 초기화
  RGB_LED.setBrightness(100);                 // pixel의 밝기 조절 (0~255)
  RGB_LED.show();                             // 모든 픽셀 초기화 'off'

  //********* 스마트 에어콘 Setup() *********//
  dht.begin();                                // DHT 모듈 초기화
  pinMode(fan, OUTPUT);                       // fan 핀 모드를 출력으로 설정

  //********* 스마트 도어 Setup() *********//
  servo.attach(servo_pin);                    // servo 객체를 초기화, 제어핀 선언

  //********* 침입자 감지 Setup() *********//
  pinMode(piezo, OUTPUT);                     // 피에조 핀 출력으로 설정
  pinMode(IRPin, INPUT);                      // IRPin을 입력으로 설정합니다.
}

void loop() {
  Serial_CON();                               // Serial 통신을 활용한 스마트홈 제어시 사용
  Bluetooths_CON();                         // Bluetooth 통신을 활용한 스마트홈 제어시 사용
  Smart_light(R_Val, G_Val, B_Val);           // 스마트 전등 함수 호출
  Smart_Air(fan_speed);                       // 스마트 에어컨 함수 호출
  angle = Smart_Door(angle);                  // 스마트 도어 함수 호출
  if (Caps == 1) {                            // 침입자 경보시스템 사용 조건
    Smart_Alarm();                            // 이후 침입자 경보시스템 함수 호출
  }
  Serial.println("#-----------------------------------------------#");
}
