# soft_ros_arduino
This tutorial introduces a middleware software framework Robot Operating System (ROS) and walks you through the setup and use of ROS with Arduino to create more intelligent robotic systems.

[Source](https://maker.pro/arduino/tutorial/how-to-use-arduino-with-robot-operating-system-ros)

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
## Setting Up the Infrastructure


### Install ROS Noetic
* [Windows](http://wiki.ros.org/Installation/Windows) (not recommended due to many issues)
* [ubuntu](http://wiki.ros.org/Installation/Ubuntu)

* install the ros_lib package:
    * sudo apt-get install ros-noetic-rosserial
    * sudo apt-get install ros-noetic-rosserial-arduino

### Install Arduino IDE or Platformio on VSCode
* install ros_lib_arduino on arduino ide/ platformio 