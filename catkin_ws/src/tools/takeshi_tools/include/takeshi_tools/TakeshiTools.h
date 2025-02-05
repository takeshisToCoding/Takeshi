#pragma once
#include "tf/transform_listener.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <pcl/io/openni_grabber.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>
#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Point.h"
#include "sensor_msgs/PointCloud2.h"
#include "point_cloud_manager/GetRgbd.h"
#include "pcl_conversions/pcl_conversions.h"
#include "tf/transform_listener.h"
#include "tf/transform_datatypes.h"
#include "tf_conversions/tf_eigen.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/Image.h"
#include <sstream>
#include <string>
#include <vision_msgs/VisionObject.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <Eigen/Dense>

class TakeshiTools
{
private:
	static bool is_node_set;
	static tf::TransformListener* tf_listener;

public:
	static bool setNodeHandle(ros::NodeHandle* nh);
	static bool transformPoint(std::string src_frame, float inX, float inY, float inZ, std::string dest_frame, float& outX, float& outY, float& outZ);
	static void PointCloud2Msg_ToCvMat(sensor_msgs::PointCloud2& pc_msg, cv::Mat& bgr_dest, cv::Mat& pc_dest);
	static void PointCloud2Msg_ToCvMat(const sensor_msgs::PointCloud2::ConstPtr& pc_msg, cv::Mat& bgr_dest, cv::Mat& pc_dest);
};
