#include <Arduino.h>
#include "Motor.h"
#include "rosserial.h"
#include "ros.h"
#include "TeensyThreads.h"

int32_t v_left = 0;
int32_t v_right = 0;
float vel_linear_x;
float vel_linear_y;
float vel_angular_z;
float vel_motor_left_step_s;
float vel_motor_right_step_s;
unsigned long time1, time2;

#define BAUD (9600)

// ros::NodeHandle nh;
// ros::Subscriber<geometry_msgs::Twist> cmd_sub("cmd_vel", commandCallback);

void setup()
{
  // threads.addThread(main_velocity);
  main_velocity();

}

void loop()
{
}