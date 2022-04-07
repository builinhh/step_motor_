/**
  ******************************************************************************
  * @file    motor.cpp
  * @author  linhbv4 - M3 Team
  * @version V1.0.0
  * @date    27-12-2021
  * @brief   .
  ******************************************************************************
  */


#include "Motor.h"
#include <Arduino.h>
#include "TeensyThreads.h"
#include <AccelStepper.h>

extern int32_t x;
extern int32_t v_left;
extern int32_t v_right;
extern float vel_linear_x;
extern float vel_linear_y;
extern float vel_angular_z;
extern float vel_motor_left_step_s;
extern float vel_motor_right_step_s;
extern unsigned long time1;
extern unsigned long time2;

AccelStepper motor_left(1, STEP_MOTOR_1, DIR_MOTOR_1);
AccelStepper motor_right(1, STEP_MOTOR_2, DIR_MOTOR_2);

void setup_motor()
{
    pinMode(ENABLE_MOTOR_1, OUTPUT);
    pinMode(ENABLE_MOTOR_2, OUTPUT);
    digitalWrite(ENABLE_MOTOR_1, LOW);
    digitalWrite(ENABLE_MOTOR_2, LOW);
    motor_left.setMaxSpeed(1000);
    motor_left.setAcceleration(1000);
    motor_right.setMaxSpeed(1000);
    motor_right.setAcceleration(1000);
}

float get_rpm_right()
{ 
  float v_right_rad=0, w_r_s, vel_right_step;
  v_right = vel_linear_x + vel_angular_z * (PI / 30) * d_robot;
  w_r_s = 2 * v_right_rad / d_robot;
  v_right = w_r_s / PI * 30;
  vel_right_step = 10/3 * v_right;
  return vel_right_step; // step/s
}

float get_rpm_left()
{ 
  float v_left_rad=0, w_l_s, vel_left_step;
  v_left = vel_linear_x - vel_angular_z * (PI / 30) * d_robot;
  w_l_s = 2 * v_left_rad / d_robot;
  v_left = w_l_s / PI * 30;
  vel_left_step = 10/3 * v_left;
  return vel_left_step; // step/s
}

void Motor_left(void)
{
  if((unsigned long) (millis() - time1) > 1)
  {
    if(digitalRead(STEP_MOTOR_1) == LOW)
      {
        digitalWrite(STEP_MOTOR_1, HIGH);
      }
    else
    {
      digitalWrite(STEP_MOTOR_1, LOW);
    }
    time1 = millis();
  }
}

void Motor_right(void)
{
  if((unsigned long) (millis() - time2) > 1)
  {
    if(digitalRead(STEP_MOTOR_2) == LOW)
      {
        digitalWrite(STEP_MOTOR_2, HIGH);
      }
    else
    {
      digitalWrite(STEP_MOTOR_2, LOW);
    }
    time2 = millis();
  }
}
void main_velocity()
{
  setup_motor();
  while(1)
  {
    // vel_motor_left_step_s =  get_rpm_left();
    // vel_motor_right_step_s = get_rpm_right();
    // motor_left.setSpeed(200);
    // motor_left.runSpeed();
    // motor_right.setSpeed(200);
    // motor_right.runSpeed();
    Motor_left();
    Motor_right();
    threads.yield();
  }
}