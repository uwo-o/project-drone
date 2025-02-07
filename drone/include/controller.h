#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "motor.h"
#include "constants.h"

class Controller
{
private:
    Motor _motor1;
    Motor _motor2;
    Motor _motor3;
    Motor _motor4;

public:
    Controller(int pin1, int pin2, int pin3, int pin4);
    void start();
    void stop();
    void forward();
    void backward();
    void left();
    void right();
    void up();
    void down();
    void rotateLeft();
    void rotateRight();
};

#endif