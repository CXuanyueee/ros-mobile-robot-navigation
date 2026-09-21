// Reconstructed portfolio example based on the navigation exercise.
// Sends a simple relative goal to move_base via actionlib.

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv) {
    ros::init(argc, argv, "simple_goal_portfolio");

    MoveBaseClient client("move_base", true);
    while (!client.waitForServer(ros::Duration(5.0))) {
        ROS_INFO("Waiting for move_base action server...");
    }

    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "base_footprint";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = 1.0;
    goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending a 1 m forward navigation goal");
    client.sendGoal(goal);
    client.waitForResult();

    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO("Goal reached");
        return 0;
    }

    ROS_WARN("Navigation goal was not completed successfully");
    return 1;
}
