#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;

// set variabel pin untuk lampu
int lamp = LED_BUILTIN;

void setup()
{
    Serial.begin(115200);

    // set Wifi SSID dan passwordnya
    WiFiMulti.addAP("Bismillah", "mbohlaliaku");

    // set pin mode ke output
    pinMode(2, OUTPUT);
}

void loop()
{
    // tunggu koneksi Wifi
    if((WiFiMulti.run() == WL_CONNECTED))
    {
        HTTPClient http;

        // ganti dengan URL API Last Feed punyamu sendiri
        http.begin("https://api.arkademy.com:8443/v0/arkana/device/IO/dummy_device/gpio/control");

        // mulai koneksi dan ambil HTTP Header
        int httpCode = http.GET();

        // httpCode akan bernilai negatif bila error
        if(httpCode > 0)
        {
            // cetak httpCode ke Serial
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // bila nilai dari server diterima
            if(httpCode == HTTP_CODE_OK)
            {
                // cetak string json dari server
                String json = http.getString();
                Serial.println(json);

                // cek value json
                if(json == "{\"value\":\"1\",\"code\":200}"){
                    // set ke LOW untuk menyalakan
                    digitalWrite(2, LOW);
                } else {
                    // set ke HIGH untuk mematikan
                    digitalWrite(2, HIGH);
                }
            }

        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        // tutup koneksi HTTP
        http.end();
    }

    delay(5000);
}
