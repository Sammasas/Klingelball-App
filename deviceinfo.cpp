#include "deviceinfo.h"

DeviceInfo::DeviceInfo(QBluetoothDeviceInfo d){
    this->device = d;
}

QString DeviceInfo::getAddress(){
    return device.address().toString();
}
