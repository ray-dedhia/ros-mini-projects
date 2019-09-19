#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // create node
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nodehandle;
  // create publisher
  ros::Publisher pub_msgs = nodehandle.advertise<std_msgs::String>("msgs", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok()) {
    // get user input
    std::string str_msg;
    std::cout << "Enter message here: ";
    std::getline(std::cin, str_msg);

    // publish user input
    std_msgs::String ss_msg;   
    std::stringstream ss;
    ss << str_msg;
    ss_msg.data = ss.str();

    ROS_INFO("%s", ss_msg.data.c_str());

    pub_msgs.publish(ss_msg);

    ros::spinOnce(); 
    loop_rate.sleep();

    // if str_msg is "-1", exit
    if (str_msg == "-1") {
      ros::spinOnce(); 
      loop_rate.sleep();

      return 0;
    }
    
  }

  return 0;
}
