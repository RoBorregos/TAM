#include <WiFi.h>
#include <WiFiUdp.h>

#include "config.h"  // Sustituir con datos de vuestra red
#include "UDP.hpp"
#include "Utils.hpp"
#include "Utils_UDP.hpp"

int led_status = 3;

void setup() 
{
  pinMode(2, OUTPUT);
  
   Serial.begin(115200);

   ConnectWiFi_STA();
   ConnectUDP(); // El error esta en esta funcion justo al final
}

void loop() 
{
  int value_recieved = GetUDP_Packet();
   if(value_recieved != -1) {
    led_status = value_recieved;
    Serial.println(led_status);
    digitalWrite(2, led_status);
   }
   //SendUDP_Packet("abcde");
}
