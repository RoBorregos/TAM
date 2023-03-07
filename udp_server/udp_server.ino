#include <WiFi.h>
#include <WiFiUdp.h>

#include "config.h"  // Sustituir con datos de vuestra red
#include "UDP.hpp"
#include "Utils.hpp"
#include "Utils_UDP.hpp"

void setup() 
{
  pinMode(2, OUTPUT);
  
   Serial.begin(115200);

   ConnectWiFi_STA();
   ConnectUDP(); // El error esta en esta funcion justo al final
}

void loop() 
{
   GetUDP_Packet();
   //SendUDP_Packet("abcde");
}
