#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
public:
    Motor(int pin);
    void setSpeed(int speed);
    int getSpeed();

private:
    int _pin;
    int _speed;
};

#endif