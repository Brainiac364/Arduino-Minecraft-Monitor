/*
  ESP8266 Based Minecraft Monitor

  This is a simple example code of the Arduino Minecraft Monitor designed to run on
  ESP8266 based boards.  The board will connect to your WIFI network, and then request
  data from the server and turn on an LED if the server is online.

  Created 02.09.2021
  By Brainiac364

  https://github.com/Brainiac364/Arduino-Minecraft-Monitor

*/

// First include the libraries we need
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoMinecraftMonitor.h>

// Change the SSID and Password to match the WIFI network you want to connect to
#ifndef STASSID
#define STASSID "ssid" //CHANGE ME
#define STAPSK  "password" //CHANGE ME
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

  /*
     Change the below to the IP of the Minecraft Server and its Query port.
     Important Note:
     This is Minecraft Query port NOT *necessarily* the game port.
     Query must be enabled in the server.properties file of your Minecraft Server.
     The query port *can* be the same as the game port, but may be set differently.
     Make sure you have the following settings set in your Minecraft
     server.properties file:
     enable-query=true
     query.port=25565 (or a port of your choice between 1 and 65535)
     Your network must also be set up to allow UDP connections to this port.
  */
  
IPAddress server(1, 2, 3, 4); //CHANGE ME
uint16_t port = 25565;        //CHANGE ME

ArduinoMinecraftMonitor mc(server, port);

// Define the LED Pin
int ledPin = 5;

void setup() {
  Serial.begin(115200);
  while (!Serial) { //Wait for a serial connection
    ;
  }

  // The following code was taken from the ESP8266Wifi Client Example:
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
     
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  
  // The following code was adapted from Thomas's original example:
  Serial.println("Starting Minecraft Monitor");
  
  pinMode(ledPin, OUTPUT);     // Initialize the LED pin as an output
  
}

void loop() {

  /* 
   *  Try to connect to the Minecraft Server and collect its status
   *  .getStats() returns a boolean TRUE if it is able to successfully connect
   *  to the server and FALSE if it is unable to reach the server or the server
   *  is offline.
   */
  
  if (mc.getStats()) { //If we are able to connect to the server:
    Serial.println("The server is up!");
    
    digitalWrite(ledPin, HIGH);  // Turn the LED on by making the voltage HIGH
    
  } else { //If we are unable to connect to the server:
    Serial.println("An error occurred, or the server is down!");
    
    digitalWrite(ledPin, LOW);  // Turn the LED off by making the voltage LOW
  }

  
  Serial.println("-----------------");
  // Make sure you adjust the delay to poll the server at a reasonable rate
  delay(5000);


}
