#include <Servo.h>  
Servo servo;    
void setup() {
  servo.attach(13);  
  Serial.begin(9600);  
}

void loop() {
  servo.write(180); 
}
