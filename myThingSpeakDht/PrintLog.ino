void printLog()
{
  Serial.print("온도: 섭씨 " + String(t) );
  Serial.print(" 도, 습도: " + String(h));
  Serial.println("퍼센트. Thingspeak 에 전송");
}
