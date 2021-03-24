
void setup() {
  Serial.begin(9600);
  int i = 0;
  for( i < 10 ) {
    Serial.print("while i : ");
    Serial.print(i);
    Serial.println(", Hello World!");
    i++
  }
}

void loop() {
  
}
