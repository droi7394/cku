void getDataFromSensor_dht()
{
  h = dht.readHumidity();
  t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) // 매개변수가 숫자가 아니면 true 
   {
       Serial.println("Failed to read sensor data from DHT11.");
       return;
   }
}
