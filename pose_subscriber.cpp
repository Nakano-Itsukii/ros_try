/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程将订阅/turtle1/pose话题，消息类型turtlesim::Pose
 */
 
#include <ros/ros.h>
#include "turtlesim/Pose.h"
#include <geometry_msgs/Twist.h>
#include <iostream>

// 接收到订阅的消息后，会进入消息回调函数
void poseCallback(const geometry_msgs::Twist&  msg )
{
    // 将接收到的消息打印出来
        // int x = msg.angular[0][0];
        // int y = msg.angular[0][1];
        // int z = msg.angular[0][2];
        // int a = msg.linear[0][0];
        // int b = msg.linear[0][1];
        // int c = msg.linear[0][2];

    // cout << msg.angular << msg.linear << endl;
    ROS_INFO("Turtle velocity: x:%.6f, y:%.6f", msg.linear.x, msg.angular.z);
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "velocity_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Subscriber velocity_sub = n.subscribe("/turtle1/cmd_vel", 10, poseCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
