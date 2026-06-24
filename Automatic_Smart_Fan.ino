#include <DHT.h>

#define DHTTYPE DHT11
const int DHTPIN = 9;
const int ENABLE = 5;
const int DIRA = 3;
const int DIRB = 4;
int fanSpeed = 255;
float roomTemp = 29.50;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  delay(2000);
  ;float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  if(t > roomTemp){
    analogWrite(ENABLE,fanSpeed);
    delay(10);
  }else{
    analogWrite(ENABLE,0);
  }

}

