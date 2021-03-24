int a = 49;
int b = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    b = Serial.read();
    Serial.println(b);

    if(a==b){ // 1를 입력하시오
      Serial.println("Hello World!");
    }


    else{ // 0를 입력하시오
      Serial.println("Hello!");
    }
  }
}
