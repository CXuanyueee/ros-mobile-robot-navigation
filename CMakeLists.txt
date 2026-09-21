cmake_minimum_required(VERSION 2.8.3)
project(ros_mobile_robot_navigation_portfolio)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  move_base_msgs
  actionlib
)

catkin_package()
include_directories(${catkin_INCLUDE_DIRS})

add_executable(portfolio_talker src/talker.cpp)
target_link_libraries(portfolio_talker ${catkin_LIBRARIES})

add_executable(portfolio_listener src/listener.cpp)
target_link_libraries(portfolio_listener ${catkin_LIBRARIES})

add_executable(simple_goal_portfolio src/simple_goal.cpp)
target_link_libraries(simple_goal_portfolio ${catkin_LIBRARIES})
