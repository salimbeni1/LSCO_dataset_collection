# OS1 Example Code
Sample code for connecting to and configuring the OS1, reading and visualizing
data, and interfacing with ROS.

See the `README.md` in each subdirectory for details.

## Steve's Directions

So ouster gives you some tools to set up a direct connection to the sensor from you computer. I'd argue these are a bit obtuse and they should really provide a set of scripts to set this up automatically as a daemon. However, since I am also using this as a development tool, I don't want this always running in the background on my machines so I provide the directions below to setup the network connection.

### One time setup

These are bash commands in Linux to setup the connection. These steps only need to happen the first time you set up the laser. After the first time, when you establish the network connection to the sensor, you can just select this created network profile. **Ensure the sensor is powered off and disconnected at this point.**

The `[eth name]` is the nework interface you're connecting to. On older Linux systems, that's `eth0` or similar. In newer versions, its `enp...` or `enx...` when you look at the output of `ifconfig`.

```
 ip addr flush dev [eth name]
 ip addr show dev [eth name]
```

The output you see from `show` should look something like `[eth name] ... state DOWN ...`. Its only important that you see `DOWN` and not `UP`. Next, lets setup a static IP address for your machine so you can rely on this in the future. Ouster uses the 10.5.5.* range, and I don't see a compelling reason to argue with it. 

```
sudo ip addr add 10.5.5.1/24 dev [eth name]

```

Now, lets setup the connection. At this point you may now plug in and power on your sensor. 

```
sudo ip link set [eth name] up
sudo addr show dev [eth name]
```

The output you see from `show` should look something like `[eth name] ... state UP ...`. Its only important that you see `UP` now and not `DOWN`. At this point, you've setup the networking needed for the one time setup. 

### Connection

We can setup the network connection to the sensor now with the proper settings. Note: This command could take up to 30 seconds to setup, be patient. If after a minute you see no results, then you probably have an issue. Start the instructions above over. Lets set up the network

```
sudo dnsmasq -C /dev/null -kd -F 10.5.5.50,10.5.5.100 -i [eth name] --bind-dynamic
``` 

Instantly you should see something similar to:

```
dnsmasq: started, version 2.75 cachesize 150
dnsmasq: compile time options: IPv6 GNU-getopt DBus i18n IDN DHCP DHCPv6 no-Lua TFTP conntrack ipset auth DNSSEC loop-detect inotify
dnsmasq-dhcp: DHCP, IP range 10.5.5.50 -- 10.5.5.100, lease time 1h
dnsmasq-dhcp: DHCP, sockets bound exclusively to interface enxa0cec8c012f8
dnsmasq: reading /etc/resolv.conf
dnsmasq: using nameserver 127.0.1.1#53
dnsmasq: read /etc/hosts - 10 addresses

```

You need to wait until you see something like:

```
dnsmasq-dhcp: DHCPDISCOVER(enxa0cec8c012f8) [HWaddr]
dnsmasq-dhcp: DHCPOFFER(enxa0cec8c012f8) 10.5.5.87 [HWaddr]
dnsmasq-dhcp: DHCPREQUEST(enxa0cec8c012f8) 10.5.5.87 [HWaddr]
dnsmasq-dhcp: DHCPACK(enxa0cec8c012f8) 10.5.5.87 [HWaddr] os1-SerialNumXX
```

Now you're ready for business. Lets see what IP addgress its on (10.5.5.87). Lets ping it

```
ping 10.5.5.87
```

and we're good to go!

### ROS Connection

Now that we have a connection over the network, lets view some data. After building your catkin workspace with this package, source the install space. Run

```

roslaunch ouster_ros os1.launch os1_udp_dest:=10.5.5.1 os1_hostname:=10.5.5.87
```

Using the os1_udp_dest as the IP address of your computer (will be 10.5.5.1 if you follow the instructions above) and os1_hostname is the IP or `.local` of the lidar itself. This may change for each of you but should be something between 10.5.5.{50-100}. See the `dnsmasq` output or check with `nmap -SP 10.5.5.*/24`. 

Now that your connection is up (hopefully), you can view this information in RViz. Open an RViz session and subscribe to the points and IMU topics in the laser frame.

Have fun!


## Contents
* [ouster_client/](ouster_client/README.md) contains an example C++ client for the OS1 sensor
* [ouster_viz/](ouster_viz/README.md) contains a visualizer for the OS1 sensor
* [ouster_ros/](ouster_ros/README.md) contains example ROS nodes for publishing point cloud messages

## Sample Data
* Sample sensor output usable with the provided ROS code is available
  [here](https://data.ouster.io/sample-data-1.12)
