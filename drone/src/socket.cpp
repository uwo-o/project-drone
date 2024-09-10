#include "socket.h"

bool setupSocket()
{
    bool success = true;
    WiFi.begin(WIFI_SSID, WIFI_PWS);
    Serial.println("\nConnecting");

    int timeout = 300;

    while (WiFi.status() != WL_CONNECTED)
    {

        if (timeout == 0)
        {
            success = false;
            break;
        }

        Serial.print(".");
        delay(100);
        timeout--;
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());

    return success;
}

void loopSocket()
{
}