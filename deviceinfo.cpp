#include "deviceinfo.h"

DeviceInfo::DeviceInfo(QBluetoothDeviceInfo d){
    this->device = d;
}

QString DeviceInfo::getAddress(){
    //implement IOS version -> see deviceinfo on lowenergyscanner
    return device.address().toString();
}
