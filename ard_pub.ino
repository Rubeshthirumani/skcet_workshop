#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher pub("arduino_string", &str_msg);

void setup() {
  nh.initNode();
  nh.advertise(pub);
}

void loop() {
  // Replace this with your desired string message
  String message = "Hello, ROS!";
  
  // Convert the string to a ROS string message
  str_msg.data = message.c_str();
  
  pub.publish(&str_msg);
  nh.spinOnce();
  
  // Add a delay if needed
  delay(1000); // 1-second delay between publishing messages
}
