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
    {
        Serial.print("Acc: ");
        Serial.print(data->acc_x);
        Serial.print(" ");
        Serial.print(data->acc_y);
        Serial.print(" ");
        Serial.print(data->acc_z);
        Serial.print(" | Gyro: ");
        Serial.print(data->gyro_x);
        Serial.print(" ");
        Serial.print(data->gyro_y);
        Serial.print(" ");
        Serial.print(data->gyro_z);
        Serial.print(" | Temp: ");
        Serial.println(data->temp);
    }

    delay(1000);
}