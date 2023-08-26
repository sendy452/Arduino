/* *********************************************************************************** *
 *          Microcontroller Board Setting Tools
 *          - Board        --> NodeMCU 1.0 (ESP-12E Module)
 *          - Upload Speed --> 921600
 *          - Port         --> COM__ ??? (listen list on your device)
 *          
 *          Pin configuration RFID-MFRC522
 *          - D0 (GPIO16) --> RST
 *          - D8 (GPIO15) --> SDA/SS
 *          - D5 (GPIO12) --> SCK
 *          - D6 (GPIO14) --> MISO
 *          - D7 (GPIO13) --> MOSI
 *
 *          Pin Configuration DHT 11
 *          - D4 --> output
 * 
 * *********************************************************************************** */

// RFID library 
#include <SPI.h>
#include <MFRC522.h>
// ESP wifi library
#include <ESP8266WiFi.h>
// DHT library
#include <DHT.h>
#include <DHT_U.h>

// Pin RFID
#define SS_PIN        D8
#define RST_PIN       D0
// Pin DHT 
#define DHT_PIN D4

#define LED_PIN LED_BUILTIN

byte uid[4];
String cardID;

String tag = "4328711C";
String card = "D4921429";

MFRC522 rfid(SS_PIN, RST_PIN); 
DHT dht(DHT_PIN, DHT11);

float t;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  
  // initial DHT and LED Pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  dht.begin();

  // Initial MFRC RFID Reader Module 
  rfid.PCD_Init();
  rfid.PCD_SetAntennaGain(rfid.RxGain_max);
}

void loop() {
  // DHT11
  sendDht();
  if(t>40){
    Serial.print("Suhu masih : "); Serial.println(t + " C");
  }else if (t>0 && t<40) {
    Serial.print("Suhu stabil : "); Serial.println(t + " C");
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
      for (byte i=0; i<4; i++) {
        uid[i] = rfid.uid.uidByte[i];
      }
      printHex(rfid.uid.uidByte, rfid.uid.size);
      Serial.println();
        
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }else{
    Serial.println("Sensor DHT Error");
  }
}

void printHex(byte *buffer, byte bufferSize) {
  cardID = "";
  // Serial.print("Card Found \n");

  for (byte i = 0; i < bufferSize; i++) 
  {    
    cardID += String(buffer[i] < 0x10 ? "0" : "");
    cardID += String(buffer[i], HEX);
    cardID.toUpperCase();
  } 
  if (cardID == tag) {
    Serial.print("Pintu Terbuka, Tag ID :  ");
  }else if(cardID == card) {
    Serial.print("Pintu Terbuka, Card ID : ");
  } else {
    Serial.print("Tag/Card RFID Not Found");
  }
  Serial.print(cardID);
}

void sendDht(){ //Pengaturan Variabel Sensor dan Virtual Pin
  t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}

