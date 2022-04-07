/**
  ******************************************************************************
  * @file    rosserial.cpp
  * @author  linhbv4 - M3 Team
  * @version V1.0.0
  * @date    27-12-2021
  * @brief   .
  ******************************************************************************
  */

 #include "rosserial.h"
 #include <Arduino.h>
 #include "geometry_msgs/Twist.h"
 
extern float vel_linear_x;
extern float vel_linear_y;
extern float vel_angular_z;

void commandCallback(const geometry_msgs::Twist& cmd_msg)
{
  vel_linear_x = cmd_msg.linear.x;
  vel_linear_y = cmd_msg.linear.y;
  vel_angular_z = cmd_msg.angular.z;
}
void setup_rosserial(void)
{

}