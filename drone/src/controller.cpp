#include "controller.h"

Controller::Controller(int pin1, int pin2, int pin3, int pin4)
    : _motor1(pin1), _motor2(pin2), _motor3(pin3), _motor4(pin4)
{
}

void Controller::start()
{
    _motor1.setSpeed(IDLE_VEL);
    _motor2.setSpeed(IDLE_VEL);
    _motor3.setSpeed(IDLE_VEL);
    _motor4.setSpeed(IDLE_VEL);
}

void Controller::stop()
{
    _motor1.setSpeed(0);
    _motor2.setSpeed(0);
    _motor3.setSpeed(0);
    _motor4.setSpeed(0);
}

void Controller::forward()
{
    _motor1.setSpeed(MAX_VEL);
    _motor2.setSpeed(MAX_VEL);
    _motor3.setSpeed(IDLE_VEL);
    _motor4.setSpeed(IDLE_VEL);
}

void Controller::backward()
{
    _motor1.setSpeed(IDLE_VEL);
    _motor2.setSpeed(IDLE_VEL);
    _motor3.setSpeed(MAX_VEL);
    _motor4.setSpeed(MAX_VEL);
}

void Controller::left()
{
    _motor1.setSpeed(IDLE_VEL);
    _motor2.setSpeed(MAX_VEL);
    _motor3.setSpeed(IDLE_VEL);
    _motor4.setSpeed(MAX_VEL);
}

void Controller::right()
{
    _motor1.setSpeed(MAX_VEL);
    _motor2.setSpeed(IDLE_VEL);
    _motor3.setSpeed(MAX_VEL);
    _motor4.setSpeed(IDLE_VEL);
}

void Controller::up()
{
    _motor1.setSpeed(MAX_VEL);
    _motor2.setSpeed(MAX_VEL);
    _motor3.setSpeed(MAX_VEL);
    _motor4.setSpeed(MAX_VEL);
}

void Controller::down()
{
    _motor1.setSpeed(LOW_VEL);
    _motor2.setSpeed(LOW_VEL);
    _motor3.setSpeed(LOW_VEL);
    _motor4.setSpeed(LOW_VEL);
}

void Controller::step()
{
    int motor1 = _motor1.getSpeed();
    int motor2 = _motor2.getSpeed();
    int motor3 = _motor3.getSpeed();
    int motor4 = _motor4.getSpeed();

    analogWrite(MOTOR1_PIN, motor1);
    analogWrite(MOTOR2_PIN, motor2);
    analogWrite(MOTOR3_PIN, motor3);
    analogWrite(MOTOR4_PIN, motor4);
}