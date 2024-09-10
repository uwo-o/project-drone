#include <Arduino.h>
#include "socket.h"
#include "constants.h"

void setup()
{
    Serial.begin(115200);

    if (DEVELOPMENT)
        delay(10000);

    if (DEVELOPMENT)
        Serial.println("Setting up all components.");

    bool socket_status = setupSocket();

    if (DEVELOPMENT)
        Serial.println("");

    if (DEVELOPMENT)
        Serial.printf("%s Wifi and socket.", socket_status ? "[OK]" : "[ERROR]");
}

void loop()
{
    loopSocket();
    delay(1000);
}