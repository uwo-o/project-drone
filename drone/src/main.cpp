#include <Arduino.h>
#include "socket.h"
#include "buzzer.h"
#include "constants.h"
#include "mpu_6050.h"

void setup()
{
    Serial.begin(115200);
    setupBuzzer();
    buzzer_accept();

    if (DEVELOPMENT)
        delay(10000);

    buzzer_accept();

    if (DEVELOPMENT)
        Serial.println("Setting up all components.");

    bool socket_status = setupSocket();
    bool mpu_status = setup_mpu6050();

    if (DEVELOPMENT)
        Serial.printf("\n%s Wifi and socket.", socket_status ? "[OK]" : "[ERROR]");

    if (DEVELOPMENT)
        Serial.printf("\n%s MPU6050.", mpu_status ? "[OK]" : "[ERROR]");

    if (!socket_status || !mpu_status)
    {
        if (DEVELOPMENT)
            Serial.println("\nError setting components.");
        buzzer_error();
        return;
    }

    if (DEVELOPMENT)
        Serial.println("\nAll components are ready.");

    buzzer_accept();
}

void loop()
{
    loopSocket();
    MpuData *data = read_mpu6050();

    if (DEVELOPMENT)
        print_mpu_data(data);

    delay(1000);
}