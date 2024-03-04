/**********************************************/
//Filename: deviceinfo.cpp
//Author: Samuel Zeillinger
//Created On: 1.December 2023 18:26
//Description: deviceinfo class implementation
/**********************************************/


#include "deviceinfo.h"

DeviceInfo::DeviceInfo(QBluetoothDeviceInfo d){
    this->device = d;
}

QString DeviceInfo::getAddress(){
    return device.address().toString();
}
