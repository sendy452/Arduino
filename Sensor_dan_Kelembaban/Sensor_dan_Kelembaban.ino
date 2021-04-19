#include <dht.h>
#define sensor A0
dht DHT;

void setup(){
    Serial.begin(9600);
    delay(500);
    Serial.println("Sensor Cuyy");
    delay(1000);
    
  }

void loop(){
    DHT.read11(sensor);
    
    Serial.println("");
    Serial.print("Kelembaban Udara : ");
    Serial.print(DHT.humidity);
    Serial.println("%");
    Serial.print("Suhu : ");
    Serial.print(DHT.temperature);
    Serial.print(" C");
    delay(5000);
  }
