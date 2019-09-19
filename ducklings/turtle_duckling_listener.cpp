#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  // turtle2
  ros::service::waitForService("spawn"); 
  ros::ServiceClient add_turtle_2 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_2;
  add_turtle_2.call(srv_2);
  ros::Publisher turtle_vel_2 = 
    node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

  // turtle3
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle_3 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_3;
  add_turtle_3.call(srv_3);
  ros::Publisher turtle_vel_3 = 
    node.advertise<geometry_msgs::Twist>("turtle3/cmd_vel", 10);

  // turtle4
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle_4 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_4;
  add_turtle_4.call(srv_4);
  ros::Publisher turtle_vel_4 = 
    node.advertise<geometry_msgs::Twist>("turtle4/cmd_vel", 10);

  // turtle5
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle_5 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_5;
  add_turtle_5.call(srv_5);
  ros::Publisher turtle_vel_5 = 
    node.advertise<geometry_msgs::Twist>("turtle5/cmd_vel", 10);

  // turtle6
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle_6 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_6;
  add_turtle_6.call(srv_6);
  ros::Publisher turtle_vel_6 = 
    node.advertise<geometry_msgs::Twist>("turtle6/cmd_vel", 10);

  // turtle7
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle_7 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_7;
  add_turtle_7.call(srv_7);
  ros::Publisher turtle_vel_7 = 
    node.advertise<geometry_msgs::Twist>("turtle7/cmd_vel", 10);

  // turtle8
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle_8 = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv_8;
  add_turtle_8.call(srv_8);
  ros::Publisher turtle_vel_8 = 
    node.advertise<geometry_msgs::Twist>("turtle8/cmd_vel", 10);

  tf::TransformListener listener;

  ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform_2;
    tf::StampedTransform transform_3;
    tf::StampedTransform transform_4;
    tf::StampedTransform transform_5;
    tf::StampedTransform transform_6;
    tf::StampedTransform transform_7;
    tf::StampedTransform transform_8;
    try {
      ros::Time timezero = ros::Time(0);
      // turtle2 transform
      listener.waitForTransform("/turtle2", "/turtle1",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle2", "/carrot1",
                                timezero, transform_2);
      // turtle3 transform
      listener.waitForTransform("/turtle3", "/turtle2",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle3", "/carrot2",
                                timezero, transform_3);
      // turtle4 transform
      listener.waitForTransform("/turtle4", "/turtle3",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle4", "/carrot3",
                                timezero, transform_4);
      // turtle5 transform
      listener.waitForTransform("/turtle5", "/turtle4",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle5", "/carrot4",
                                timezero, transform_5);
      // turtle6 transform
      listener.waitForTransform("/turtle6", "/turtle5",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle6", "/carrot5",
                                timezero, transform_6);
      // turtle7 transform
      listener.waitForTransform("/turtle7", "/turtle6",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle7", "/carrot6",
                                timezero, transform_7);
      // turtle8 transform
      listener.waitForTransform("/turtle8", "/turtle7",
                                timezero, ros::Duration(1.0) );
      listener.lookupTransform("/turtle8", "/carrot7",
                                timezero, transform_8);
    } catch (tf::TransformException ex) {
        ROS_ERROR("%s", ex.what());
    }

    // turtle2 velocity
    geometry_msgs::Twist vel_msg_2;
    vel_msg_2.angular.z = 4.0 * atan2(transform_2.getOrigin().y(),
                            transform_2.getOrigin().x());
    vel_msg_2.linear.x = 0.5 * sqrt(pow(transform_2.getOrigin().x(), 2) +
                            pow(transform_2.getOrigin().y(), 2));
    turtle_vel_2.publish(vel_msg_2);

    // turtle3 velocity
    geometry_msgs::Twist vel_msg_3;
    vel_msg_3.angular.z = 4.0 * atan2(transform_3.getOrigin().y(),
                            transform_3.getOrigin().x());
    vel_msg_3.linear.x = 0.5 * sqrt(pow(transform_3.getOrigin().x(), 2) +
                            pow(transform_3.getOrigin().y(), 2));
    turtle_vel_3.publish(vel_msg_3);

    // turtle4 velocity
    geometry_msgs::Twist vel_msg_4;
    vel_msg_4.angular.z = 4.0 * atan2(transform_4.getOrigin().y(),
                            transform_4.getOrigin().x());
    vel_msg_4.linear.x = 0.5 * sqrt(pow(transform_4.getOrigin().x(), 2) +
                            pow(transform_4.getOrigin().y(), 2));
    turtle_vel_4.publish(vel_msg_4);

    // turtle5 velocity
    geometry_msgs::Twist vel_msg_5;
    vel_msg_5.angular.z = 4.0 * atan2(transform_5.getOrigin().y(),
                            transform_5.getOrigin().x());
    vel_msg_5.linear.x = 0.5 * sqrt(pow(transform_5.getOrigin().x(), 2) +
                            pow(transform_5.getOrigin().y(), 2));
    turtle_vel_5.publish(vel_msg_5);

    // turtle6 velocity
    geometry_msgs::Twist vel_msg_6;
    vel_msg_6.angular.z = 4.0 * atan2(transform_6.getOrigin().y(),
                            transform_6.getOrigin().x());
    vel_msg_6.linear.x = 0.5 * sqrt(pow(transform_6.getOrigin().x(), 2) +
                            pow(transform_6.getOrigin().y(), 2));
    turtle_vel_6.publish(vel_msg_6);

    // turtle7 velocity
    geometry_msgs::Twist vel_msg_7;
    vel_msg_7.angular.z = 4.0 * atan2(transform_7.getOrigin().y(),
                            transform_7.getOrigin().x());
    vel_msg_7.linear.x = 0.5 * sqrt(pow(transform_7.getOrigin().x(), 2) +
                            pow(transform_7.getOrigin().y(), 2));
    turtle_vel_7.publish(vel_msg_7);

    // turtle8 velocity
    geometry_msgs::Twist vel_msg_8;
    vel_msg_8.angular.z = 4.0 * atan2(transform_8.getOrigin().y(),
                            transform_8.getOrigin().x());
    vel_msg_8.linear.x = 0.5 * sqrt(pow(transform_8.getOrigin().x(), 2) +
                            pow(transform_8.getOrigin().y(), 2));
    turtle_vel_8.publish(vel_msg_8);

    rate.sleep();
  }
  return 0;
};
