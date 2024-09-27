#include "motor_controller.h"

Motor *motors[4];

int motor1_reference_speed = 0;
int motor2_reference_speed = 0;
int motor3_reference_speed = 0;
int motor4_reference_speed = 0;

bool is_reference_speed_set = false;

void setup_motors()
{
    motors[0] = new Motor(MOTOR_1_PIN);
    motors[1] = new Motor(MOTOR_2_PIN);
    motors[2] = new Motor(MOTOR_3_PIN);
    motors[3] = new Motor(MOTOR_4_PIN);
}

void start_motors()
{
    if (!is_reference_speed_set)
        return;

    motors[0]->set_speed(motor1_reference_speed);
    motors[1]->set_speed(motor2_reference_speed);
    motors[2]->set_speed(motor3_reference_speed);
    motors[3]->set_speed(motor4_reference_speed);

    for (int i = 0; i < 4; i++)
        motors[i]->start();
}

void stop_motors()
{
    for (int i = 0; i < 4; i++)
        motors[i]->stop();
}

void set_motors_speed(int speed[])
{
    for (int i = 0; i < 4; i++)
        motors[i]->set_speed(speed[i]);
}

void step_motors()
{
    for (int i = 0; i < 4; i++)
        motors[i]->step();
}

void rotate_left()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 + motor1_reference_speed;
    speed[1] = 225 - motor2_reference_speed;
    speed[2] = 225 - motor3_reference_speed;
    speed[3] = 225 + motor4_reference_speed;
    set_motors_speed(speed);
}

void rotate_right()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 - motor1_reference_speed;
    speed[1] = 225 + motor2_reference_speed;
    speed[2] = 225 + motor3_reference_speed;
    speed[3] = 225 - motor4_reference_speed;
    set_motors_speed(speed);
}

void move_forward()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 - motor1_reference_speed;
    speed[1] = 225 - motor2_reference_speed;
    speed[2] = 225 + motor3_reference_speed;
    speed[3] = 225 + motor4_reference_speed;
    set_motors_speed(speed);
}

void move_backward()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 + motor1_reference_speed;
    speed[1] = 225 + motor2_reference_speed;
    speed[2] = 225 - motor3_reference_speed;
    speed[3] = 225 - motor4_reference_speed;
    set_motors_speed(speed);
}

void move_left()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 + motor1_reference_speed;
    speed[1] = 225 - motor2_reference_speed;
    speed[2] = 225 + motor3_reference_speed;
    speed[3] = 225 - motor4_reference_speed;
    set_motors_speed(speed);
}

void move_right()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 - motor1_reference_speed;
    speed[1] = 225 + motor2_reference_speed;
    speed[2] = 225 - motor3_reference_speed;
    speed[3] = 225 + motor4_reference_speed;
    set_motors_speed(speed);
}

void up()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 + motor1_reference_speed;
    speed[1] = 225 + motor2_reference_speed;
    speed[2] = 225 + motor3_reference_speed;
    speed[3] = 225 + motor4_reference_speed;
    set_motors_speed(speed);
}

void down()
{
    if (!is_reference_speed_set)
        return;

    int speed[4] = {0, 0, 0, 0};
    speed[0] = 225 - motor1_reference_speed;
    speed[1] = 225 - motor2_reference_speed;
    speed[2] = 225 - motor3_reference_speed;
    speed[3] = 225 - motor4_reference_speed;
    set_motors_speed(speed);
}

void set_motors_reference(MpuData gyro)
{
    motor1_reference_speed = (int)(gyro.gyro_x / 255);
    motor2_reference_speed = (int)(gyro.gyro_z / 255);
    motor3_reference_speed = (int)(gyro.gyro_x / 255);
    motor4_reference_speed = (int)(gyro.gyro_z / 255);
    is_reference_speed_set = true;
}