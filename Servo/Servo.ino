

/* www.nyebarilmu.com */

#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo;     // variable untuk menyimpan posisi data
int pos = 00;   
         
void setup(){ 
 myservo.attach(D0); //sinyal data kabel motor servo dikonekan di pin 7 Arduino
} 

void loop(){ 
 for(pos = 00; pos <= 90; pos += 1)  //fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
 {
  myservo.write(pos); //prosedur penulisan data PWM ke motor servo
  delay(500);       
 } 
 for(pos = 90; pos>=1; pos-=1)  //fungsi perulangan yang akan dijadikan PWM dengan penurunan 1
 {                              
  myservo.write(pos);                 
  delay(10);                        
 }
}

