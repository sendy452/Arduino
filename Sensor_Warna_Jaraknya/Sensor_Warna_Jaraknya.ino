#include <dht.h>
#define sensor A0
dht DHT;

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, INPUT);

  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);

  Serial.begin(9600);
  delay(500);
  Serial.println("M'Bako");
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(sensor);
  
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  red = pulseIn(5, digitalRead(5) == HIGH ? LOW : HIGH);
  digitalWrite(3, HIGH);
  blue = pulseIn(5, digitalRead(5) == HIGH ? LOW : HIGH);
  digitalWrite(4, HIGH);
  green = pulseIn(5, digitalRead(5) == HIGH ? LOW : HIGH);

  Serial.print("RED: ");
  Serial.print(red);
  Serial.print("  ");
  Serial.print("GREEN: ");
  Serial.print(green);
  Serial.print("  ");
  Serial.print("BLUE: ");
  Serial.print(blue);
  Serial.println("  ");
  delay(1000);


}

