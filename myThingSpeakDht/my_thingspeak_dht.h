#include <DHT.h>  // Include DHT library. 

#define DHTPIN 2          // GPIO pin 번호를 입력한다. D4 -> GPIO2  (D1 mini pin map 참조)
DHT dht(DHTPIN, DHT11);
 
float h =0.0;
float t = 0.0;
