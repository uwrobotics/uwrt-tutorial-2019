#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Point.h"

#include <iostream>

ros::Publisher velPub;

float goalx = 10, goaly = 10;


void PoseCallback(turtlesim::Pose msg)
{
  //std::cout << "Received message: " << msg.data << std::endl;
  float dx = goalx - msg.x;
  float dy = goaly - msg.y;

  float heading = msg.theta; // 0 to 2*pi
  float goalHeading = atan2(dy,dx); //-pi to pi

  float headingErr = goalHeading - heading; // -3pi to 3pi
  if (headingErr < -M_PI)
  {
    headingErr += 2*M_PI;
  }
  else if (headingErr > M_PI)
  {
    headingErr -= 2*M_PI;
  }

  float dist = sqrt(dx*dx + dy*dy);


  geometry_msgs::Twist vel;
  if (dist > 0.01)
  {
  vel.linear.x = sqrt(dist) * 0.5;
  vel.angular.z = headingErr * 1.5;
  }
  velPub.publish(vel);
}

void GoalCallback(geometry_msgs::Point msg)
{
  //std::cout << "Received message: " << msg.data << std::endl;
  goalx = msg.x;
  goaly = msg.y;
}

int main(int argc, char** argv)
{
  // Initialize this node with the name publisher_node
  ros::init(argc, argv, "subscriber_node");

  ros::NodeHandle nh;

  // Create a subscriber to listen to the message
  ros::Subscriber posesub = nh.subscribe("/turtle1/pose", 1, PoseCallback);
  ros::Subscriber goalsub = nh.subscribe("/test_turtle/goal", 1, GoalCallback);
  velPub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

  // Listen for messages
  ros::spin();
}

