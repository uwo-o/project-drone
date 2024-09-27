#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "motor.h"
#include "mpu_6050.h"

void setup_motors();
void start_motors();
void stop_motors();
void set_motors_speed(int speed[]);
void set_motors_reference(MpuData *data);
void step_motors();
void rotate_left();
void rotate_right();
void move_forward();
void move_backward();
void move_left();
void move_right();
void up();
void down();

#endif