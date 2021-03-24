void setup() {
  Serial.begin(9600);
}
void loop() {
  int val_1 = analogRead(A3);
  int val_2 = analogRead(A4);
  int val_3 = analogRead(A5);
  
  Serial.print("1:");
  Serial.print(val_1);
  Serial.print(" 2:");
  Serial.print(val_2);
  Serial.print(" 3:");
  Serial.println(val_3);
}
