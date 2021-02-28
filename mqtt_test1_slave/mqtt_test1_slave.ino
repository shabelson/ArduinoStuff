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



const char  IP[] = "192.168.11.105";
const char ssid[] ="IAAC-WIFI";
const char pswd[] =  "enteriaac2013";
//void subscribeReceive(char* topic, byte* payload, unsigned int length);

WiFiClient client;
ESP8266WiFiMulti WiFiMulti;
PubSubClient MQTT_CLIENT(client);
//
  void subscribeReceive(char* topic, byte* payload, unsigned int length)
{
  
  Serial.print("enter Subscribe");
  //Print the topic
  Serial.print("Topic: ");
  Serial.println(topic);
 
  // Print the message
  Serial.print("Message: ");
  for(int i = 0; i < length; i ++)
  {
  Serial.print(char(payload[i]));
  }
 
  // Print a newline
  Serial.println("");
}

void setup() {
  Serial.begin(115200);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid,pswd);
  MQTT_CLIENT.setCallback(subscribeReceive);
  MQTT_CLIENT.setServer(IP,1883);

}

void loop() {
    //check wifi and connect
    if ((WiFiMulti.run() == WL_CONNECTED)) {
      Serial.println("WIFIIIII");
    
    //check if mqtt connected and connect
    if (!MQTT_CLIENT.connected()){
    Serial.println("mqtt not connect");
    Serial.println("entered reconnect");
    
    MQTT_CLIENT.setClient(client);
    while (!MQTT_CLIENT.connected()){
      MQTT_CLIENT.connect("esp_slave");
      MQTT_CLIENT.subscribe("/testmsg/master");
      MQTT_CLIENT.subscribe("/testmsg/masterListen");
       
      Serial.println("MQTT Connecting");
      delay(3000);
       }  
    }
    
    //Run subscribing/publishing etc
    
   // while (MQTT_CLIENT.connected()){
      //Serial.println(IP); 
       //Serial.println(MQTT_CLIENT.connected());
       Serial.println("bef sub");
       MQTT_CLIENT.loop();
       //MQTT_CLIENT.subscribe("/testmsg/master");
       Serial.println("aft sub");
       delay(1000);
   // }
    }
    
    //3
    //reconnect();
    

   //
   Serial.println("passed sub");
  delay(2000);
  }
