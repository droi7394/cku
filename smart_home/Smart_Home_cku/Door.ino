//****************** 스마트 도어 함수 ******************//
int Smart_Door(int angles) {
  if (angles != init_angle) {                     // 블루투스에게 상태를 전달 받은 상황인지 아닌지 구분.
    control_num++;                            // 상태유지 카운트.
    lcd.setCursor(0, 0);
    lcd.print("Door Open Count ");
    lcd.setCursor(0, 1);
    lcd.print("         = "); lcd.print(control_num); lcd.print("ms ");

    if (control_num == CONST_INTERVAL_TIME) {                    // 문이 열리고 3초가 지나가는지 확인.
      control_num = 0;                        // 명령 받기 전의 상태로 복귀
      angles = init_angle;                             // 서보모터 각도 초기화.
    }
  }
  else {                                      // 대기 상태라면,
    control_num = 0;                        // 명령 받기 전의 상태로 복귀
    angles = init_angle;                             // 서보모터 각도 초기화.
  }
  Serial.print("angle : "); Serial.print(angles);
  Serial.print(", control : "); Serial.println(control_num);
  servo.write(angles);                        // 명령받은 각도로 서보모터 동작
  delay(100);

  return angles;                              // 조건문 이후, 각도 값을 리턴.
}
