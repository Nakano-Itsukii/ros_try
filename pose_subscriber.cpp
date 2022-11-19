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

	// ROS节点初始化
	ros::init(argc, argv, "velocity_publisher");

    // 创建节点句柄
    ros::NodeHandle n1;
    
    // 创建节点句柄
	ros::NodeHandle n2;

    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Subscriber velocity_sub = n1.subscribe("/turtle1/cmd_vel", 10, poseCallback);

    // 创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10
	ros::Publisher turtle_vel_pub = n2.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // 设置循环的频率
	ros::Rate loop_rate(10);

	int count = 0;

    while (ros::ok())
	{
	    // 初始化geometry_msgs::Twist类型的消息
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x = 0.5;
		vel_msg.angular.z = 0.2;

	    // 发布消息
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", 
				vel_msg.linear.x, vel_msg.angular.z);

	    // 按照循环频率延时
	    loop_rate.sleep();

           // 循环等待回调函数
    poseCallback(vel_msg);
	}



 

    return 0;
}





	

