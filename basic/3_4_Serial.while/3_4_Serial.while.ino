
void setup() {
  Serial.begin(9600);
  for(int i = 0 ; i < 10 ; i++) {
    Serial.print("for i : ");
    Serial.print(i);
    Serial.println(", Hello World!");
  }
}

void loop() {
  
}
