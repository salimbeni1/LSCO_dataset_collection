# LSCO dataset collection

## LSCO ( Lidar, Stereo Cameras, Odometry )

This is a repo to group all the necessarys tools to collect the LSCO dataset.


## dependencies

make sure you are using ros-melodic !
on ubuntu 16

## Setup

prepare a ros workspace with both ros packages : 
**ros/ouster_os1** and **ros/stereo_camera_pub**

compile the workspace new packages with :
```
catkin_make
```

### cameras setup

more details on **camera_setup/**

or just use the scripts ( follow the order ) : 
```
./buildKernel.sh

./lowerScript.sh

./upperScript.sh

./publishTopics.sh
```

### lidar setup

more details on **ros/ouster_os1**

or just use the script : 
```
./setupLidar.sh
```

## recording

you can use rosbag record to collect the published topics

or use the script:
```
./record.sh
```







