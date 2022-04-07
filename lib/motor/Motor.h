/**
  ******************************************************************************
  * @file    motor.h
  * @author  linhbv4 - M3 Team
  * @version V1.0.0
  * @date    27-12-2021
  * @brief   .
  ******************************************************************************
  */


 #ifndef MOTOR_H_
 #define MOTOR_H_

 #include <Arduino.h>
 #include <rosserial.h>
 #include <AccelStepper.h>
 
 #define STEP_MOTOR_1 5
 #define DIR_MOTOR_1 4
 #define STEP_MOTOR_2 7
 #define DIR_MOTOR_2 8
 #define ENABLE_MOTOR_1 1
 #define ENABLE_MOTOR_2 0

#define r_wheel 0.06;
#define d_robot 0.212;

void get_velocity_wheel_right();
void get_velocity_wheel_left();
void setup_motor();
void main_velocity();
float get_rpm_right();
float get_rpm_left();
void Motor_left();
void Motor_right();

#endif