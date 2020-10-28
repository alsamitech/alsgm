#!/bin/sh
wget -qO - https://packages.lunarg.com/lunarg-signing-key-pub.asc | sudo apt-key add -
wget -qO /etc/apt/sources.list.d/lunarg-vulkan-1.2.141-bionic.list https://packages.lunarg.com/vulkan/1.2.141/lunarg-vulkan-1.2.141-bionic.list
apt update
apt install vulkan-sdk

# sudo version below, but if you are using doas, just prefix it
# (assuming you're using vulkan, you probably already know what you're doing, so no need for documentation)
# Good luck creating this with alsgm!

#wget -qO - https://packages.lunarg.com/lunarg-signing-key-pub.asc | sudo apt-key add -
#sudo wget -qO /etc/apt/sources.list.d/lunarg-vulkan-1.2.141-bionic.list https://packages.lunarg.com/vulkan/1.2.141/lunarg-vulkan-1.2.141-bionic.list
#sudo apt update
#sudo apt install vulkan-sdk
