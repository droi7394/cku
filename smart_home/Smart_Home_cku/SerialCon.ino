void Serial_CON() {
  if (Serial.available()) {                // 만약 블루투스로부터 받은 통신이 있다면,
    if (Serial.find("R")) {                // 문자 "R" 을 검색
      R_Val = Serial.parseInt();           // 이후 숫자를 read와 달리 연속된 숫자로 빨강LED 값으로 저장.
      Serial.print("R"); Serial.print(R_Val);
    }
    if (Serial.find("G")) {                // 문자 "G" 을 검색
      G_Val = Serial.parseInt();           // 이후 숫자를 read와 달리 연속된 숫자로 녹색LED 값으로 저장.
      Serial.print("G"); Serial.print(G_Val);
    }
    if (Serial.find("B")) {                // 문자 "B" 을 검색
      B_Val = Serial.parseInt();           // 이후 숫자를 read와 달리 연속된 숫자로 파랑LED 값으로 저장.
      Serial.print("B"); Serial.print(B_Val);
    }
    if (Serial.find("F")) {                // 문자 "F"를 검색
      fan_speed = Serial.parseInt();       // 이후 숫자를 read와 달리 연속된 숫자로 Fan 속도로 저장.
      Serial.print("F"); Serial.print(fan_speed);
    }
    if (Serial.find("D")) {                // 문자 "D"를 검색
      angle = Serial.parseInt();           // 이후 숫자를 read와 달리 연속된 숫자로 서보모터 각도로 저장.
      control_num = 1;
      Serial.print("D"); Serial.println(angle);
    }
    if (Serial.find("CapsON")) {           // 문자 "CapsON"를 검색
      Serial.println("CapsON");
      angle = init_angle;
      fan_speed = 0;
      R_Val = 0;
      G_Val = 0;
      B_Val = 0;
      Caps = 1;
    }
  }
}
