#!/usr/bin/python3.8

import rospy
from std_msgs.msg import Int32  # Change the message type if needed

def publish_to_arduino():
    # Initialize the ROS node
    rospy.init_node('python_to_arduino_publisher', anonymous=True)

    # Define the topic to publish data to (must match the topic subscribed by Arduino)
    pub = rospy.Publisher('arduino_data', Int32, queue_size=10)  # Change topic name and message type as needed

    # Set the publishing rate (in Hz)
    rate = rospy.Rate(1)  # 1 Hz, adjust as needed

    while not rospy.is_shutdown():
        # Replace this with your data to send to the Arduino
        data_to_send = 0  # Change this value as needed

        # Publish the data
        pub.publish(data_to_send)
        rospy.loginfo("Data sent to Arduino: %d", data_to_send)

        # Sleep to maintain the publishing rate
        rate.sleep()

if __name__ == '__main__':
    try:
        publish_to_arduino()
    except rospy.ROSInterruptException:
        pass
