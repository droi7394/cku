int Buzzer_Pin = 7;

void setup() {
  pinMode(Buzzer_Pin, OUTPUT);
}

void loop() {
  tone(Buzzer_Pin, 523); // 5옥타브 도
  delay(1000);
  tone(Buzzer_Pin, 587); // 5옥타브 레
  delay(1000);
  tone(Buzzer_Pin, 659); // 5옥타브 미
  delay(1000);
}
