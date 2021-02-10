/*
   Name: Arduino-Minecraft-Monitor-Test
   Purpose: A Simple Example of the Arduino-Minecraft-Monitor
   Author: Thomas Cope
   
   **Update by Brainiac364 02.09.2021:
   This was the original code to be used with the Ethernet Shield for the Arduino UNO
   The library's ArduinoMinecraftMonitor.h file must be changed as follows to make this work:
   
   Line 6 must be changed from 
      #include <WiFiUdp.h> 
   to 
      #include <EthernetUdp.h>
      
   Line 39 must be changed from 
      WiFiUDP udpPacket; 
   to 
      EthernetUDP udpPacket;

   This may be patched in future updates to the library by Thomas.
   
*/

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <ArduinoMinecraftMonitor.h>

byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
};

IPAddress server(1, 2, 3, 4); //CHANGE ME
uint16_t port = 25565;        //CHANGE ME
EthernetClient ethClient;
ArduinoMinecraftMonitor mc(server, port);

void setup() {
  Serial.begin(9600);
  while (!Serial) { //Wait for a serial connection
    ;
  }
  Serial.println("Starting Minecraft Monitor Demo");
  Serial.println("Getting IP Arduino Address via DHCP");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("DHCP Failed");
    for (;;)
      ;
  } else {
    Serial.println("DHCP OK!");
  }
  /*
     Change the below to your IP and Minecraft Query port.
     Important Note:
     This is Minecraft Query port NOT the game port
     make sure you have the following settings set in your Minecarft
     server.properties file:
     enable-query=true
     query.port=25565
  */
  if (mc.getStats()) {
    Serial.println("Got Stats OK!");
  } else {
    Serial.println("An error occurred!");
  }
}

void loop() {

  Serial.println("-----------------");

  Serial.print("MOTD: ");
  Serial.println(mc.getMOTD());

  Serial.print("Game Type: ");
  Serial.println(mc.getGameType());

  Serial.print("Game ID: ");
  Serial.println(mc.getGameID());

  Serial.print("Minecraft Version: ");
  Serial.println(mc.getMCVersion());

  Serial.print("Minecraft Plugins: ");
  Serial.println(mc.getPlugins());

  Serial.print("Current Map: ");
  Serial.println(mc.getMCMap());

  Serial.print("Online Players Count: ");
  Serial.println(mc.getOnlinePlayers());

  Serial.print("Max Player Count: ");
  Serial.println(mc.getMaxPlayers());

  Serial.print("Server Port: ");
  Serial.println(mc.getHostPort());

  Serial.print("Server IP: ");
  Serial.println(mc.getHostIP());

  Serial.print("Online Player Names: ");
  Serial.println(mc.getPlayers());

  delay(5000);

  if (mc.getStats()) {
    Serial.println("Got Stats OK!");
  } else {
    Serial.println("An error occurred!");
  }
}
