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
catkin_init_workspace
source devel/setup.bash
# add the new packages
catkin_make
```

### cameras setup

more details on **camera_setup/**

or just use the scripts ( follow the order ) : 
```
./buildKernel.sh

# Power on Camera 1
connect camera 1 via USB - B
put device on Live Mode
./upperScript.sh

# Power on Camera 0
connect camera 0 via USB - B
put device on Live Mode
./lowerScript.sh


./publishTopics.sh
```

### lidar setup

more details on **ros/ouster_os1**

or just use the script :
```
# follow the scipt instructions ( do not connect the Lidar first )
./setupLidar.sh
```

## recording

you can use rosbag record to collect the published topics

or use the script:
```
./record.sh
```







