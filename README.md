# Arduino-Minecraft-Monitor

A Simple Arduino library to get the status of a Minecraft Server (players count, player names etc)

Designed to work with either the Arduino Ethernet Shield or ESP8266 boards

## Features

Data Returned: 
* MOTD
* Game Type
* Game ID
* Minecraft Version
* Minecraft Plugins
* Current Map
* Online Players Count
* Max Player Count
* Server Port
* Server IP
* Online Player Names

## Tutorial

Please see examples

## Notes

You must use the server IP and the server Query port not the Minecraft port.
Make sure you have the following settings set in your Minecarft server.properties file:
```cpp
enable-query=true
query.port=25565
```

## Installing

Download the .zip file and import using the IDE "Add .ZIP Library" function.  For more information see: https://www.arduino.cc/en/guide/libraries
