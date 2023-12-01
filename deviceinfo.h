#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QBluetoothDeviceInfo>
#include <QBluetoothAddress>


class DeviceInfo
{
private:
    QBluetoothDeviceInfo device;

public:
    DeviceInfo(QBluetoothDeviceInfo &d);
    QString getAddress();
    QString getName(){return device.name();}
    QBluetoothDeviceInfo getDevice();
    void setDevice(const QBluetoothDeviceInfo &dev);
};

#endif // DEVICEINFO_H
