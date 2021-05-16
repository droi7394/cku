#include <ESP8266WiFi.h>  // Include ESP8266 library for D1 mini
#include "my_thing_speak.h"
#include "my_thingspeak_dht.h"

WiFiClient wiFiClient; 

void setup() 
{
  Serial.begin(115200);
  delay(10);
  dht.begin();
  
  Serial.println("Try Connecting to ");
  Serial.println(ssid);
  
  
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
      delay(500);
      Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}
 
void loop() 
{

  getDataFromSensor_dht();
  
  if (wiFiClient.connect(server,80))   //  thingspeak server 에 접속
  {  
    makePostData();
  }
  printLog();
  Serial.println("...");
  delay(DELAY_TIME);
}
