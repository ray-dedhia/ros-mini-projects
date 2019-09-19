#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);
  while (node.ok()){
    transform.setOrigin( tf::Vector3(-.75*cos(ros::Time(0).toSec()), .75*sin(ros::Time(0).toSec()), 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    // make carrot1 (for turtle2 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle1", "carrot1"));
    // make carrot2 (for turtle3 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle2", "carrot2"));
    // make carrot3 (for turtle4 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle3", "carrot3"));
    // make carrot4 (for turtle5 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle4", "carrot4"));
    // make carrot5 (for turtle6 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle5", "carrot5"));
    // make carrot6 (for turtle7 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle6", "carrot6"));
    // make carrot7 (for turtle8 to follow)
    br.sendTransform(tf::StampedTransform(transform, ros::Time(0), "turtle7", "carrot7"));
    rate.sleep();
  }
  return 0;
};
