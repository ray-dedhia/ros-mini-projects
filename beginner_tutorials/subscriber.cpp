#include "ros/ros.h"
#include "std_msgs/String.h"

void msg_callback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  std::string str_msg;
  str_msg = msg->data.c_str();
  if (str_msg == "-1") {
    exit(0);
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nodehandle;
  ros::Subscriber sub_msgs = nodehandle.subscribe("msgs", 1000, msg_callback);
  ros::spin();

  return 0;
}

