#!/usr/bin/env python
# VITA, EPFL
import rospy
import time
import cv2
from sensor_msgs.msg import Image, CameraInfo, LaserScan, PointCloud2
from std_msgs.msg import Int32
import message_filters
from cv_bridge import CvBridge, CvBridgeError


class Sender(object):

    def __init__(self):
        self.pub_sync = rospy.Publisher('/Sync/camera0_image', Image, queue_size=1)
        self.pub_sync1 = rospy.Publisher('/Sync/camera1_image', Image, queue_size=1)
        self.pub_sync2 = rospy.Publisher('/Sync/lidar', PointCloud2, queue_size=1)

    def send(self, camera0, camera1, lidar):
        # Publish commands:
        self.pub_sync.publish(camera0)
        self.pub_sync1.publish(camera1)
        self.pub_sync2.publish(lidar)


def callback_sync(camera0_image, camera1_image, lidar_info):
    
    global camera0, camera1, lidar

    camera0 = camera0_image
    camera1 = camera1_image
    lidar = lidar_info



def main():
    # Initialize ROS sync node
    rospy.init_node("sync")
    camera0_image_sub = message_filters.Subscriber('/Camera/camera0_image', Image)
    camera1_image_sub = message_filters.Subscriber('/Camera/camera1_image', Image)
    lidar_sub = message_filters.Subscriber('/Lidar/lidar_info', PointCloud2)

    dt_sync = max(rospy.get_param("/camera0/dt_camera0"), rospy.get_param("/camera1/dt_camera1"), rospy.get_param("/lidar/dt_lidar"))
    f_sync = int(1/dt_sync)
    rate = rospy.Rate(f_sync)
    sender = Sender()

    global bridge, camera0, camera1, lidar

    camera0 = Image()
    camera1 = Image()
    lidar = PointCloud2()
    ts = message_filters.TimeSynchronizer([camera0_image_sub, camera1_image_sub, lidar_sub], f_sync)
    ts.registerCallback(callback_sync)
    bridge = CvBridge()
    rospy.loginfo("sync Node Ready")
    rospy.sleep(1.)

    sync_info = Image()

    while not rospy.is_shutdown():
        start = time.time()
        
        # Send sync commands + visualization topics via ROS
        sender.send(camera0, camera1, lidar)

        # Calculate node computation time
        computation_time = time.time() - start
        
        if computation_time > dt_sync:
            rospy.logwarn("Sync computation time higher than node period by " + str(computation_time-dt_sync) + " seconds")

        rate.sleep()


if __name__ == "__main__":

    try:
        main()

    except rospy.ROSInterruptException:
        pass
