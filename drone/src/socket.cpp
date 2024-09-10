#include "socket.h"

bool setupSocket()
{
    bool success = true;
    WiFi.begin(WIFI_SSID, WIFI_PWS);

    int timeout = 100;

    while (WiFi.status() != WL_CONNECTED)
    {

        if (timeout <= 0)
        {
            success = false;
            break;
        }

        Serial.print(".");
        delay(100);
        timeout--;
    }

    return success;
}

void loopSocket()
{
}