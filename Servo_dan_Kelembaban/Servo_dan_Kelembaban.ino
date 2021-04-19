#include <dht.h>
#define sensor A0
dht DHT;

#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo;     // variable untuk menyimpan posisi data
int pos = 00;   

void setup(){
 Serial.begin(9600);
 delay(500);
 Serial.println("Tes Kelembaban");
 delay(1000);

 myservo.attach(2); //sinyal data kabel motor servo dikonekan di pin 2 Arduino
}

void loop(){
 delay(1000);
 DHT.read11(sensor);
 Serial.println("");
 Serial.print("Kelembaban Udara : ");
 Serial.print(DHT.humidity);
 Serial.println(" %");
 delay(500);

 if(DHT.humidity >= 50){
  for(pos = 90; pos>=1; pos-=1)  //fungsi perulangan yang akan dijadikan PWM dengan penurunan 1
  {                              
    myservo.write(pos);                 
    delay(10);                        
  }
  for(pos = 00; pos <= 90; pos += 1)  //fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
  {
    myservo.write(pos); //prosedur penulisan data PWM ke motor servo     
  } 
 }
}
