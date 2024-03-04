/**********************************************/
//Filename: deviceinfo.h
//Author: Samuel Zeillinger
//Created On: 1 December 2023 18:26
//Description: class to store info of Bluetooth device
/**********************************************/

#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QBluetoothDeviceInfo>
#include <QBluetoothAddress>
#include <QObject>


class DeviceInfo
{

private:
    QBluetoothDeviceInfo device;

public:
    DeviceInfo(QBluetoothDeviceInfo d);
    QString getAddress();
    QString getName(){ return device.name();}
    QBluetoothDeviceInfo *getDevice(){return &device;};
    void setDevice(const QBluetoothDeviceInfo &dev);
};

#endif // DEVICEINFO_H
