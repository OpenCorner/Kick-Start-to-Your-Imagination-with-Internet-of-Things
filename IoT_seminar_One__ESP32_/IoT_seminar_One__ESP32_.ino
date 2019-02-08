#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char *ssid = "ENTER ACCESS POINT NAME";
const char *password = "ENTER PASSWORD";

int LED1 = 14 ;

String Page = "<!DOCTYPE html><html><head><h2>OPENCORNER WEB SERVER DEMO </h2></head><body><h1 style=\"color: blue;font-family:verdana;font-size:300%;\">DEMO SEMINAR 1</h1><p><a href=\"LEDOn\"><button style=\"color: green;font-family:verdana;padding: 50px 75px;font-size:300%\">ON</button></a>&nbsp;<a href=\"LEDOff\"><button style=\"color: red;font-family:verdana;padding: 50px 75px;font-size:300%\" >OFF</button></a></p></body></html>";



AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
pinMode(LED1,OUTPUT);
  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {

  request->send(200, "text/html", Page );
  });

  server.on("/LEDOn", HTTP_GET, [](AsyncWebServerRequest * request) {

    Serial.println("LED ON");
    digitalWrite(LED1,HIGH);
        request->send(200, "text/html", Page );

  });

  server.on("/LEDOff", HTTP_GET, [](AsyncWebServerRequest * request) {

    Serial.println("LED OFF");
    digitalWrite(LED1,LOW);

        //request->send(200, "text/html", Page );


  });

  server.begin();
}

void loop() {}
