#include <dht.h>
#define sensor A0
dht DHT;

int s0_pin =1;
int s1_pin =2;
int s2_pin =3;
int s3_pin =4;
int out_pin =5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(s0_pin, OUTPUT);
  pinMode(s1_pin, OUTPUT);
  pinMode(s2_pin, OUTPUT);
  pinMode(s3_pin, OUTPUT);
  pinMode(out_pin, INPUT);
  digitalWrite(s0_pin,HIGH);
  digitalWrite(s1_pin,LOW);

  Serial.begin(9600);
  delay(500);
  Serial.println("Suhu, Kelembaban, dan Warna Daging Ikan");
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(sensor);

  if(DHT.humidity >= 40.00 && DHT.humidity < 59.00){
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    }  
  else{
    digitalWrite(8, LOW);
    }
  Serial.println("");
  Serial.print("Kelembaban Udara : ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  Serial.print("Suhu : ");
  Serial.print(DHT.temperature);
  Serial.println(" C");
  delay(1000);

  digitalWrite(s2_pin,LOW);
  digitalWrite(s3_pin,LOW);
  int red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color, 25,72,255,0);
  delay(50);

  digitalWrite(s2_pin,HIGH);
  digitalWrite(s3_pin,HIGH);
  int green_color = pulseIn(out_pin, LOW);
  green_color = map(green_color, 30,90,255,0);
  delay(50);

  digitalWrite(s2_pin,LOW);
  digitalWrite(s3_pin,HIGH);
  int blue_color = pulseIn(out_pin, LOW);
  blue_color = map(blue_color, 25,70,255,0);
  delay(50);

  Serial.print("RED: ");
  Serial.print(red_color);
  Serial.print("  ");

  Serial.print("GREEN: ");
  Serial.print(green_color);
  Serial.print("  ");

  Serial.print("BLUE: ");
  Serial.print(blue_color);
  Serial.println("  ");
  delay(1000);

  if( red_color <= 260 && red_color >= 200 && green_color <= 250 && green_color >= 180 && blue_color <= 250 && blue_color >= 170){
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
  else{
    digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
    }

}

