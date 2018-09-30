#include <iostream>
#include <ros/ros.h>


#include <geometry_msgs/Twist.h>
#include "turtlesim/Pose.h"
#include <geometry_msgs/Point.h>



float goalx = 1, goaly = 1;
ros::Publisher velPub;


void GoalCallback(geometry_msgs::Point msg)
{
  goalx = msg.x;
  goaly = msg.y;
}

void PoseCallback(turtlesim::Pose msg)
{
  float dx =goalx - msg.x;
  float dy = goaly - msg.y;
  
  float dist = sqrt(dx*dx + dy*dy);
  
  float heading = msg.theta; // 0 to 2pi
  float goal_heading = atan2(dy, dx); // -pi to pi
  
  float heading_err = goal_heading - heading; //-3pi to 3pi
  
  if (heading_err > M_PI)
  {
    heading_err -= 2*M_PI;
  }
  else if (heading_err < -M_PI)
  {
    heading_err += 2*M_PI;
  }
  
  geometry_msgs::Twist vel_msg;
  
  if(dist > 0.01)
  {
    vel_msg.linear.x = dist*0.3;
    vel_msg.angular.z = heading_err * 1.5;
  }
  
  
  velPub.publish(vel_msg);
  
  
  


}



int main(int argc, char** argv)
{
  //Initialize
  ros::init(argc, argv, "turtle_control_node");
  ros::NodeHandle nh;
  
  //Create subscriber
  
  ros::Subscriber goalSub = nh.subscribe("/goal", 1, GoalCallback);
  ros::Subscriber poseSub = nh.subscribe("/turtle1/pose", 1, PoseCallback);
  velPub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1);
  
  ros::spin();

  return 0; 
  
 }


