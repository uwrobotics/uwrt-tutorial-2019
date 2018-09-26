#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <iostream>


void SubscriberCallback(std_msgs::Int32 msg)
{
  std::cout << "Received message: " << msg.data << std::endl;
}

int main(int argc, char** argv)
{
  // Initialize this node with the name publisher_node
  ros::init(argc, argv, "subscriber_node");

  ros::NodeHandle nh;

  // Create a subscriber to listen to the message
  ros::Subscriber sub = nh.subscribe("/uwrt_tut/my_topic", 1, SubscriberCallback);

  // Listen for messages
  ros::spin();
}

