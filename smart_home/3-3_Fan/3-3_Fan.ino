int Fan = 11;

void setup() {
  pinMode(Fan, OUTPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) {
    int Fan_Val = i;
    analogWrite(Fan, Fan_Val);
    delay(25);
  }
}
