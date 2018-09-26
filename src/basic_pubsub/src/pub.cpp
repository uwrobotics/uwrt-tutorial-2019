#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <iostream>


int main(int argc, char** argv)
{
  // Initialize this node with the name publisher_node
  ros::init(argc, argv, "publisher_node");

  ros::NodeHandle nh;

  // Create a publisher so that we can publish messages
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("/uwrt_tut/my_topic",1);

  ros::Rate loopRate(5); // loop at 5Hz

  int loopNum = 0;

  while(ros::ok())
  {
    std_msgs::Int32 msg;
    msg.data = loopNum;

    // Publish the message
    std::cout << "Publishing message " << loopNum << std::endl;
    pub.publish(msg);

    loopNum++;
    loopRate.sleep();
  }
  return 0;
}
