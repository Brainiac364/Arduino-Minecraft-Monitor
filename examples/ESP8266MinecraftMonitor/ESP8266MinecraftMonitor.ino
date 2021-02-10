/*
  ESP8266 Based Minecraft Monitor

  This is a simple example code of the Arduino Minecraft Monitor designed to run on
  ESP8266 based boards.  The board will connect to your WIFI network, and then request
  data from the server and print it to your serial monitor.

  Created 02.09.2021
  By Brainiac364 and Thomas Cope

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
  Serial.println("Starting Minecraft Monitor Demo");
  
}

void loop() {

  /* 
   *  Try to connect to the Minecraft Server and collect its status
   *  .getStats() returns a boolean TRUE if it is able to successfully connect
   *  to the server and FALSE if it is unable to reach the server or the server
   *  is offline.
   */
  
  if (mc.getStats()) { //If we are able to connect to the server:
    Serial.println("Got Stats OK!");

    /*
     * Listed below are the basic functions available in the library that allow
     * you to access the current status of the server:
     */

    // .getMOTD() returns the Message of the Day as a string
    Serial.print("MOTD: ");
    Serial.println(mc.getMOTD());

    // .getGameType() returns the Game Type as a string
    Serial.print("Game Type: ");
    Serial.println(mc.getGameType());

    // .getGameID() returns the Game ID as a string
    Serial.print("Game ID: ");
    Serial.println(mc.getGameID());

    // .getMCVersion() returns the Minecraft Version as a string
    Serial.print("Minecraft Version: ");
    Serial.println(mc.getMCVersion());

    // .getPlugins() returns all of the Minecraft Plugins as a string
    Serial.print("Minecraft Plugins: ");
    Serial.println(mc.getPlugins());
    
    // .getMCMap() returns the level-name in your server.properties file as a string
    Serial.print("Current Map: ");
    Serial.println(mc.getMCMap());

    // .getOnlinePlayers() returns the number of players online as an int
    Serial.print("Online Players Count: ");
    Serial.println(mc.getOnlinePlayers());

    // .getMaxPlayers() returns the maximum number of players allowed as an int
    Serial.print("Max Player Count: ");
    Serial.println(mc.getMaxPlayers());

    // .getHostIP() returns the IP of the server
    Serial.print("Server IP: ");
    Serial.println(mc.getHostIP());
    
    // .getHostPort() returns the port of the server
    Serial.print("Server Port: ");
    Serial.println(mc.getHostPort());

    // .getPlayers() returns a string with a list of the usernames of all of the currently 
    // connected players, seperated by commas
    Serial.print("Online Player Names: ");
    Serial.println(mc.getPlayers());

    
  } else { //If we are unable to connect to the server:
    Serial.println("An error occurred, or the server is down!");
  }

  
  Serial.println("-----------------");
  // Make sure you adjust the delay to poll the server at a reasonable rate
  delay(5000);


}
