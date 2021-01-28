#!/bin/bash

cd ..
cd v4l2loopback
make
make clean
make && sudo make install
sudo depmod -a
sudo modprobe v4l2loopback video_nr=0,1
