cmake_minimum_required(VERSION 2.8.3)
project(ducklings)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp rospy tf turtlesim)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(turtle_duckling_broadcaster src/turtle_duckling_broadcaster.cpp)
target_link_libraries(turtle_duckling_broadcaster ${catkin_LIBRARIES})

add_executable(turtle_duckling_listener src/turtle_duckling_listener.cpp)
target_link_libraries(turtle_duckling_listener ${catkin_LIBRARIES})

add_executable(frame_duckling_broadcaster src/frame_duckling_broadcaster.cpp)
target_link_libraries(frame_duckling_broadcaster ${catkin_LIBRARIES})
