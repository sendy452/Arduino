int s0_pin =0;
int s1_pin =1;
int s2_pin =2;
int s3_pin =3;
int out_pin =4;


void setup() {

Serial.begin(9600);

pinMode(s0_pin, OUTPUT);
pinMode(s1_pin, OUTPUT);
pinMode(s2_pin, OUTPUT);
pinMode(s3_pin, OUTPUT);
pinMode(out_pin, INPUT);
digitalWrite(s0_pin,HIGH);
digitalWrite(s1_pin,LOW);

}


void loop() {
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

if( red_color <= 120 && red_color >= 30 && green_color <= 120 && green_color >= 40 && blue_color <= 120 && blue_color >= 40){
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
  else{
    digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
    }
 
}
