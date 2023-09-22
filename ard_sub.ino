#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;

int received_data = 0;  // Initialize with a value that indicates no data received

ros::Subscriber<std_msgs::Int32> sub("arduino_data", [](const std_msgs::Int32& msg) {
  // Callback function to handle incoming data
  received_data = msg.data;
});

void setup() {
  nh.initNode();
  nh.subscribe(sub);
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the built-in LED pin as an output
  Serial.begin(57600);
}

void loop() {
  nh.spinOnce();  // Handle ROS messages

  if (received_data == 1) {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn on LED
    Serial.println("LED turned ON");
  } else if (received_data == 0) {
    digitalWrite(LED_BUILTIN, LOW);   // Turn off LED
    Serial.println("LED turned OFF");
  }

  delay(100);  // Add a small delay to avoid rapid toggling
}
