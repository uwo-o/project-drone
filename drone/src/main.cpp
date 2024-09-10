#include <Arduino.h>
#include "socket.h"

void setup()
{
    Serial.begin(115200);
    delay(10000);
    bool socket_status = setupSocket();

    Serial.println("Setting up...");

    if (socket_status)
    {
        Serial.printf("Wifi and socket. %s", socket_status ? "[OK]" : "[ERROR]");
    }
}

void loop()
{
    loopSocket();
    delay(1000);
}