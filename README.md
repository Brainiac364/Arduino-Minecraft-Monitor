# Arduino Minecraft Monitor

This is a simple Arduino library to get the status of a Minecraft Server.  
It uses the Minecraft Query API to return information about the server, like the number of player slots, the number of players online, and their usernames.

It was originally designed to work with the Arduino Ethernet Shield but has been updated for use over WIFI with ESP8266 based boards.   

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

Examples are included and can be accessed through the "Examples from Custom Libraries"

## Notes

You must use the server IP and the server Query port not the Minecraft port.
Make sure you have the following settings set in your Minecarft server.properties file:
```cpp
enable-query=true
query.port=25565
```

## Installing

Download the library, and use the built in .ZIP Library adder in the Arduino IDE.  
More info here: https://www.arduino.cc/en/guide/libraries#toc4

## Credits

This library was originally written by Thomas Cope.  Please send him your gratitude.  I merely updated the library to be more user friendly and function on the WIFI boards, as well as cleaned up some of the documentation.
