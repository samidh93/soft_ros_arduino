# Setup up a VM ubuntu guest OS
This documentation help you understand how to: 
* setup a virtual machine on windows host with ubutu as guest operating system 
* Install ros on ubuntu vm
* Install vscode on ubuntu vm
* change permissions to share folder from windows
* change permissions to access usb port
* install platformio

# setup a virtual machine on windows host with ubutu as guest operating system 
* 1- install virtual box on windows
* 2- download ubuntu 20.04 iso image
* 3- create a vdi on Vbox with that iso
* 4- run the Vm and install ubuntu
* 5- install guest os addition

# Install ros on ubuntu vm
* follow instruction for [ubuntu](http://wiki.ros.org/Installation/Ubuntu) 

# Install vscode on ubuntu vm
* download vscode from ubuntu software

# change permissions to share folder from windows
* 1- add shared folder from the setting in Vbox
* 2- on ubuntu: run the following
    * sudo usermod -G vboxsf -a $USER

# change permissions to access usb port
* 1- add usb device from the setting in Vbox
* 2- on ubuntu: run 
    * sudo usermod -G dialout -a $USER
* 3- check if the device appears by plugin and unplugin it:
    * ls /dev/tty*

# install platformio
* 1- on vscode extensio, install platformio
* 2- be sure to have git installed:
    * sudo apt-get install git
* 3- configure git:    
    * git config --global user.name ""
    * git config --global user.email ""
    * git config -l
