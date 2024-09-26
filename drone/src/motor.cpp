#include "motor.h"

Motor::Motor(int pin)
{
    this->pin = pin;
    this->speed = 0;
    ledcSetup(MOTORS_CHANNEL, MOTORS_FREQUENCY, MOTORS_RESOLUTION);
    ledcAttachPin(pin, MOTORS_CHANNEL);
    this->max_dutty_cicle = (int)(pow(2, MOTORS_RESOLUTION) - 1);
}

void Motor::high()
{
    ledcWrite(MOTORS_CHANNEL, this->speed + 1);
}

void Motor::low()
{
    ledcWrite(MOTORS_CHANNEL, this->speed - 1);
}

void Motor::stop()
{
    ledcWrite(MOTORS_CHANNEL, 0);
}

void Motor::start()
{
    ledcWrite(MOTORS_CHANNEL, this->speed);
}

void Motor::set_speed(int speed)
{
    this->speed = speed;
    ledcWrite(MOTORS_CHANNEL, this->speed);
}