`#include <Servo.h>
Servo servo;
int servo_pin = 13;
int IRPin = 10;

void setup() {
  servo.attach(servo_pin);
  pinMode(IRPin, INPUT);
  servo.write(178);
}
void loop() {
  if (digitalRead(IRPin) == LOW) {
    servo.write(180);
  }
  else {
    servo.write(90);
  }
}
