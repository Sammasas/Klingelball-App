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
    QBluetoothDeviceInfo getDevice(){return device;};
    void setDevice(const QBluetoothDeviceInfo &dev);
};

#endif // DEVICEINFO_H
