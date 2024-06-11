#include <DHT.h>; 
 
#define DHTPIN 2       // what pin we're connected to 
#define DHTTYPE DHT22     // DHT 22  (AM2302) 
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino 
 
int chk; 
float hum;      //Stores humidity value 
float temp;     //Stores temperature value 
int relay = 7; 
void setup()  
{ 
  Serial.begin(9600); 
  pinMode(relay, OUTPUT); 
  dht.begin(); 
} 
 
void loop() { 
 
  hum = dht.readHumidity(); 
  temp = dht.readTemperature(); 
  Serial.print("Humidity: "); 
  Serial.print(hum); 
  Serial.print(" %, Temp: "); 
  Serial.print(temp); 
  Serial.println(" Celsius"); 
  if (temp < 37) 
  { 
  digitalWrite(relay, HIGH); 
  delay(1000); 
  } 
  else if (temp > 38) 
  { 
  digitalWrite(relay, LOW); 
  delay(1000); 
  } 
}  