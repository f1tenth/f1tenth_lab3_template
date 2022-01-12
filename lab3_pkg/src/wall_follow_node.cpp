#include "rclcpp/rclcpp.hpp"
#include <string>
#include "sensor_msgs/msg/laser_scan.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
/// CHECK: include needed ROS msg type headers and libraries

class WallFollow : public rclcpp::Node {

public:
    WallFollow() : Node("wall_follow_node")
    {
        /// TODO: create ROS subscribers and publishers
    }

private:
    // PID CONTROL PARAMS
    /// TODO: double kp = 
    /// TODO: double kd = 
    /// TODO: double ki = 
    double servo_offset = 0.0;
    double prev_error = 0.0;
    double error = 0.0;
    double integral = 0.0;
    // WALL FOLLOW PARAMS
    double ANGLE_RANGE = 270; // Hokuyo 10LX has 270 degrees scan
    double DESIRED_DISTANCE_RIGHT = 0.9; // meters
    double DESIRED_DISTANCE_LEFT = 0.55;
    double VELOCITY = 2.00; // meters per second
    double CAR_LENGTH = 0.50; // Traxxas Rally is 20 inches or 0.5 meters
    // Topics
    std::string lidarscan_topic = "/scan";
    std::string drive_topic = "/drive";
    /// TODO: create ROS subscribers and publishers

    double getRange(float* data, double angle)
    {
        // data: single message from topic /scan
        // angle: between -45 to 225 degrees, where 0 degrees is directly to the right
        // Outputs length in meters to object with angle in lidar scan field of view
        // make sure to take care of nans etc.
        /// TODO: implement
        return 0.0;
    }

    void pid_control(double error, double velocity)
    {
        /// TODO: pid_control
    }

    double followLeft(float* data, double leftDist) 
    {   
        // Follow left wall as per the algorithm 
        /// TODO:implement
        return 0.0;
    }

    void scan_callback(const sensor_msgs::msg::LaserScan::ConstSharedPtr scan_msg) 
    {
        /// TODO: calculate TTC

        /// TODO: publish drive/brake message
    }

};
int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WallFollow>());
    rclcpp::shutdown();
    return 0;
}