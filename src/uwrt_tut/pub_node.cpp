#include <iostream>
#include <ros/ros.h>

#include <std_msgs/Float32.h>



int main(int argc, char** argv)
{

  //Initialise node
  ros::init(argc, argv, "pub_node");
  ros::NodeHandle nh;

  //Create publisher
  ros::Publisher pub = nh.advertise<std_msgs::Float32>("/my_topic", 100);


  ros::Rate loop_rate(5);

  float num = 0;

  while(ros::ok())
  {
    std_msgs::Float32 msg;


    msg.data = num;
    num++;
    pub.publish(msg);


    loop_rate.sleep();

  }




 return 0;
}
