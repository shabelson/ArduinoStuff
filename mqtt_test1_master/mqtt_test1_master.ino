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
const char  IP[] = "192.168.11.105";
const char ssid[] ="IAAC-WIFI";
const char pswd[] =  "enteriaac2013";
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
  WiFiMulti.addAP(ssid,pswd);
   

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
      Serial.println("MQTT trying to Connect");
      delay(3000);
       }
    while (MQTT_CLIENT.connected()){
       
       Serial.println(IP); 
       Serial.println(MQTT_CLIENT.connected());
       MQTT_CLIENT.publish("/testmsg/master"," IGOR?");
       MQTT_CLIENT.publish("/testmsg/masterListen"," where are you igor?");
    }
    }
    //3
    //reconnect();
    

   //
   Serial.println("passed pub");
  delay(2000);
  }
  
