#include <LiquidCrystal.h>
#include <dht.h>
#define dht_apin A1
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

dht DHT; 
const int AirValue = 600;   //you need to replace this value with Value_1
const int WaterValue = 350;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;


void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  lcd.begin(16, 2);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  //delay(1000);//Wait before accessing Sensor
}
void loop() {
soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent >= 100)
{
  Serial.println("100 %");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print("100 %");
  delay(250);
  lcd.clear();
}
else if(soilmoisturepercent <=0)
{
  lcd.clear();
  Serial.println("0 %");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print("0 %");
  delay(250);
  lcd.clear();
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  Serial.print(soilmoisturepercent);
  Serial.println("%");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print(soilmoisturepercent);
  lcd.print(" %");
  delay(250);
  lcd.clear();
}  
  /* tmp stuff */
  DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(100);//Wait 5 seconds before accessing sensor again.

  // Read humidity
  byte RH = DHT.humidity;
  //Read temperature in degree Celsius
  byte Temp = DHT.temperature;
}
