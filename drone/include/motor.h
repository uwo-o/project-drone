#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "constants.h"

class Motor
{
public:
    Motor(int pin);
    void high();
    void low();
    void stop();
    void start();
    void set_speed(int speed);
    void step();

private:
    int pin;
    int speed;
    int max_dutty_cicle;
};

#endif