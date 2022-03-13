# soft_ros_arduino
This tutorial introduces a middleware software framework Robot Operating System (ROS) and walks you through the setup and use of ROS with Arduino to create more intelligent robotic systems.

## What is ROS?
Robot Operating System (ROS) is one of the most popular and widely used robotics middleware software frameworks. It is an open-source platform that helps makers and developers alike to get started with robotics software without reinventing the wheel. 

![Source img](https://maker.pro/storage/31hf5Iu/31hf5IuuLOHy0KbmxGOIibQlVMhNQn8Zb8mIfmkN.png)

## Setup up a VM ubuntu guest OS
please check the [VM_UBUNTU](VM_UBUNTU.md) documentation to understand how: 
* how to setup a virtual machine on windows host with ubutu as guest operating system 
* Install ros on ubuntu vm
* Install vscode on ubuntu vm
* change permissions to share folder from windows
* change permissions to access usb port
* install platformio


## Communication Between ROS and Arduino
The ROS communication module operates on a customized TCPROS protocol within two paradigms: the many-to-many publisher-subscriber methodology, and the peer-to-peer faster services methodology. This tutorial uses the publisher/subscriber paradigm to communicate between the Arduino board and ROS running on the machine.

## Install ROS Noetic package
to install ros on the the target os:
* [Windows](http://wiki.ros.org/Installation/Windows) (not recommended due to many issues)
* [ubuntu](http://wiki.ros.org/Installation/Ubuntu)

* install the ros_lib package:
    * sudo apt-get install ros-noetic-rosserial
    * sudo apt-get install ros-noetic-rosserial-arduino

## Install library for Arduino IDE or Platformio on VSCode
* install ros_lib_arduino on arduino ide/ platformio 

## Upload code and setup hardware
* upload code on src/main.cpp and make a simple setup with a button connected to PIN 8

## Run Program

* Start the ROS Master - roscore
* Run rosserial client on the machine :
    * rosrun rosserial_python serial_node.py /dev/tty<USB# or ACM#>
* The serial port is determined at run time for either ttyUSB or ttyACM. The exact port number can be found from the Arduino IDE or using: 
    * dmesg | grep tty.
* Read published data returning if the button is pressed on the Arduino board or not: 
    * rostopic echo button_press
* Publish data to toggle the LED connected on the Arduino:
    * rostopic pub toggle_led std_msgs/UInt16 "data: 0" The data is “0” to switch off the LED and “1” to switch on the LED.