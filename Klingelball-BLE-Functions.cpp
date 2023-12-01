#include "klingelballui.h"
#include "ui_klingelballui.h"



void KlingelballUI::on_uebertragen_button_clicked()
{
    startDeviceDiscovery();

}


void KlingelballUI::printMessage(QString message){
    ui->uebertragen_button->setText(message);
}

void KlingelballUI::startDeviceDiscovery(){
#if QT_CONFIG(permissions)
    //! [permissions]
    QBluetoothPermission permission{};
    permission.setCommunicationModes(QBluetoothPermission::Access);
    switch (qApp->checkPermission(permission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(permission, this, &KlingelballUI::startDeviceDiscovery);
        return;
    case Qt::PermissionStatus::Denied:
        printMessage("Ble permission denied");
        return;
    case Qt::PermissionStatus::Granted:
        break; // proceed to search
    }
    //! [permissions]
#endif // QT_CONFIG(permissions)

    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    printMessage("Wird Übertragen...");
}

void KlingelballUI::addDevice(const QBluetoothDeviceInfo &device){
    printMessage("gefunden!");
    if(device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration){
        printMessage(device.name());
    }
}

void KlingelballUI::ScanFinished(){
    printMessage("Scan finished");

}
void KlingelballUI::ScanError(QBluetoothDeviceDiscoveryAgent::Error error){

    switch(error){

    case QBluetoothDeviceDiscoveryAgent::NoError:
        printMessage("No Error");
    break;

    case QBluetoothDeviceDiscoveryAgent::PoweredOffError:
        printMessage("Bluetooth turned off");
        break;
    case QBluetoothDeviceDiscoveryAgent::InputOutputError:
        printMessage("InOut Error");
        break;
    case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
        printMessage("InvalidAdapter");
        break;
    case QBluetoothDeviceDiscoveryAgent::UnsupportedDiscoveryMethod:
        printMessage("Error 4");
        break;
    case QBluetoothDeviceDiscoveryAgent::UnsupportedPlatformError:
        printMessage("Error 5");
        break;
    case QBluetoothDeviceDiscoveryAgent::LocationServiceTurnedOffError:
        printMessage("Error 6");
        break;
    case QBluetoothDeviceDiscoveryAgent::MissingPermissionsError:
        printMessage("Error 7");
        break;
    case QBluetoothDeviceDiscoveryAgent::UnknownError:
        printMessage("Unknown Error");
        break;
    }

}
