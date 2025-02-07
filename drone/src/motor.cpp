#include "motor.h"

Motor::Motor(int pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void Motor::setSpeed(int speed)
{
    analogWrite(_pin, speed);
}

int Motor::getSpeed()
{
    return _speed;
}