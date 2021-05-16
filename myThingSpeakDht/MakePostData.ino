void makePostData(){
  postData +="&field1=" + String(t);
  postData +="&field2=" + String(h);
  postData += "\r\n\r\n";
  
  wiFiClient.print("POST /update HTTP/1.1\n");
  wiFiClient.print("Host: api.thingspeak.com\n");
  wiFiClient.print("Connection: close\n");
  wiFiClient.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
  wiFiClient.print("Content-Type: application/x-www-form-urlencoded\n");
  wiFiClient.print("Content-Length: " + String(postData.length()));
  wiFiClient.print("\n\n");
  wiFiClient.print(postData);
  wiFiClient.stop();
}
