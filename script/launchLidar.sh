#!/bin/bash

cd ..
cd ouster_workspace
source devel/setup.bash
roslaunch ouster_ros os1.launch os1_udp_dest:=10.5.5.1 os1_hostname:=10.5.5.86

