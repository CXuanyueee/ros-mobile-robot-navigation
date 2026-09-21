// Reconstructed learning example for portfolio use.
// Demonstrates a basic ROS publisher used during ROS fundamentals practice.

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char** argv) {
    ros::init(argc, argv, "portfolio_talker");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate rate(10);

    int count = 0;
    while (ros::ok()) {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count++;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
