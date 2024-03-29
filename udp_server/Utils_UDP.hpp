boolean ConnectUDP() {
  Serial.println();
  Serial.println("Starting UDP");

  // in UDP error, block execution
  if (UDP.begin(localPort) != 1) 
  {
    Serial.println("Connection failed");
    while (true) { delay(1000); } 
  }

  Serial.println("UDP successful");
  return true;
}

void SendUDP_ACK()
{
  UDP.beginPacket(UDP.remoteIP(), remotePort);
  UDP.write(reinterpret_cast<const uint8_t*>("ACK"), 3);
  UDP.endPacket();
}

void SendUDP_Packet(String content) {
  const uint8_t* buffer = reinterpret_cast<const uint8_t*>(content.c_str());
  int length = content.length();
  UDP.beginPacket(UDP.remoteIP(), remotePort);
  UDP.write(buffer, length);
  UDP.endPacket();
}

int GetUDP_Packet(bool sendACK = true)
{
  int packetSize = UDP.parsePacket();
  if (packetSize)
  {
    // read the packet into packetBufffer
    char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
    UDP.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);

    Serial.println();
    Serial.print("Received packet of size ");
    Serial.print(packetSize);
    Serial.print(" from ");
    Serial.print(UDP.remoteIP());
    Serial.print(":");
    Serial.println(UDP.remotePort());
    Serial.print("Payload: ");
    Serial.write((uint8_t*)packetBuffer, (size_t)packetSize);
    Serial.println();
    ProcessPacket(String(packetBuffer));
    return int(packetBuffer[0]) - '0';

    //// send a reply, to the IP address and port that sent us the packet we received
    if(sendACK) SendUDP_ACK();
  } 
  delay(10);
  return -1;
}
