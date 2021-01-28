#!/bin/bash

rosbag record –split –duration=5m /Camera/camera0_image /Camera/camera1_image /os1_cloud_node/imu /os1_cloud_node/points
