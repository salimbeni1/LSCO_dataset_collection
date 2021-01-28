#!/bin/bash

ip addr  flush dev eth0
ip addr show dev eth0


sudo ip addr add 10.5.5.1/24 dev eth0

read -p "please plug and power your device and press Enter to continue"

sudo ip link set eth0 up
sudo addr show dev eth0



sudo dnsmasq -C /dev/null -kd -F 10.5.5.50,10.5.5.100 -i eth0 --bind-dynamic

