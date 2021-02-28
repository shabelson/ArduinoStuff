#include <PubSubClient.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>

//setup To All:
///optional 1st step- connect to blue tooth -> transmit mqtt data 
//connect to local wifi
//connect to mqtt broker
//collect data... etc..etc..


WiFiClient client;
const char  IP[] = "192.168.1.67";
const char ssid[] ="MiFibra-B93B";
const char pswd[] =  "3brRyg9p";
PubSubClient MQTT_CLIENT;
ESP8266WiFiMulti WiFiMulti;




void setup() {
  Serial.begin(115200);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("MiFibra-B93B","3brRyg9p");
   

}

void loop() {
    if ((WiFiMulti.run() == WL_CONNECTED)) {
    Serial.println("WIFIIIII");
    if (!MQTT_CLIENT.connected()){
    Serial.println("mqtt not connect");
    }
    Serial.println("entered reconnect");
    MQTT_CLIENT.setServer(IP,1883);
    MQTT_CLIENT.setClient(client);
    while (!MQTT_CLIENT.connected()){
      MQTT_CLIENT.connect("esp_master");
      Serial.println("MQTT Connected");
      delay(3000);
       }
       
       Serial.println(IP); 
       Serial.println(MQTT_CLIENT.connected());
       MQTT_CLIENT.publish("/testmsg/master"," IGOR?");
    }
    
    //3
    //reconnect();
    

   //
   Serial.println("passed pub");
  delay(2000);
  }
  
