#include "klingelballui.h"
#include "ui_klingelballui.h"



void KlingelballUI::on_uebertragen_button_clicked()
{
    qDebug() << "writeCharacteristik";
    if(KlingelballConnected){
        qDebug()<<"device still connected attempt to write";

    }

}


void KlingelballUI::on_searchKlingelball_clicked()
{
    startDeviceDiscovery();
}


void KlingelballUI::on_connectKlingelball_clicked()
{

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
    printMessage("suchen... ");
}

void KlingelballUI::addDevice(const QBluetoothDeviceInfo &device){
    if(device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration){
        if(device.name() == "EchoBall"){
            printMessage(device.name());
            qDebug() << device.deviceUuid().toString();
            connectDevice(device);

        }
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

void KlingelballUI::connectDevice(QBluetoothDeviceInfo currentdevice){
    QBluetoothAddress currentDeviceAddress = currentdevice.address();
    m_controller = QLowEnergyController::createCentral(currentdevice, this);

    connect(m_controller, SIGNAL(serviceDiscovered(QBluetoothUuid)), this, SLOT(serviceDiscovered(QBluetoothUuid)));
    connect(m_controller, SIGNAL(discoveryFinished()), this, SLOT(serviceScanDone()));
    connect(m_controller, SIGNAL(connected()), this, SLOT(deviceConnected()));
    connect(m_controller, SIGNAL(errorOccurred(QLowEnergyController::Error)), this, SLOT(controllerError(QLowEnergyController::Error)));
    connect(m_controller, SIGNAL(disconnected()), this, SLOT(deviceDisconnected()));

    m_controller->connectToDevice();
}

void KlingelballUI::serviceDiscovered(QBluetoothUuid uuid){
    qDebug() << "service discovered";

}

void KlingelballUI::serviceScanDone(){
    qDebug()<<"serviceScanDone";
    setupServiceDiscovery();
}

void KlingelballUI::controllerError(QLowEnergyController::Error error){
    switch(error){
        case QLowEnergyController::Error::ConnectionError:
            qDebug()<<"ConnectionError";
            break;
        case QLowEnergyController::Error::RssiReadError:
            qDebug()<<"RssiReadError";
            break;
        case QLowEnergyController::Error::UnknownError:
            qDebug()<<"UnknownError";
            break;

        case QLowEnergyController::Error::AdvertisingError:
            qDebug()<<"AdvertisingError";
            break;

        case QLowEnergyController::Error::AuthorizationError:
            qDebug()<<"AuthorizationError";
            break;

        case QLowEnergyController::Error::InvalidBluetoothAdapterError:
            qDebug()<<"InvalidBluetoothAdapterError";
            break;

        case QLowEnergyController::Error::MissingPermissionsError:
            qDebug()<<"MissingPermissionsError";
            break;

        case QLowEnergyController::Error::NetworkError:
            qDebug()<<"NetworkError";
            break;

        case QLowEnergyController::Error::NoError:
            qDebug()<<"NoError";
            break;

        case QLowEnergyController::Error::RemoteHostClosedError:
            qDebug()<<"RemoteHostClosedError";
            break;

        case QLowEnergyController::Error::UnknownRemoteDeviceError:
            qDebug()<<"UnknownRemoteDeviceError";
            break;

    }
}

void KlingelballUI::deviceConnected(){
    qDebug() << "device connected";
    KlingelballConnected = true;
    m_deviceDiscoveryAgent->stop();
    m_controller->discoverServices();
}

void KlingelballUI::deviceDisconnected(){
    qDebug() << "device disconnected";
    KlingelballConnected = false;
}

void KlingelballUI::setupServiceDiscovery(){
    qDebug()<<"setupServiceDiscovery";

    m_service = m_controller->createServiceObject(*KlingelballUUID, this);

    connect(m_service, SIGNAL(stateChanged(QLowEnergyService::ServiceState)), this, SLOT(KlingelballServiceStatechanged(QLowEnergyService::ServiceState)));
    connect(m_service, SIGNAL(errorOccurred(QLowEnergyService::ServiceError)), this, SLOT(KlingelballServiceError(QLowEnergyService::ServiceError)));
    connect(m_service, SIGNAL(characteristicRead(QLowEnergyCharacteristic,QByteArray)), this, SLOT(KlingelballCharacteristicRead(QLowEnergyCharacteristic,QByteArray)));
    connect(m_service, SIGNAL(characteristicWritten(QLowEnergyCharacteristic,QByteArray)), this, SLOT(KlingelballCharacteristicWritten(QLowEnergyCharacteristic,QByteArray)));
    connect(m_service, SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)), this, SLOT(KlingelballCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));
    connect(m_service, SIGNAL(descriptorRead(QLowEnergyDescriptor,QByteArray)), this, SLOT(KlingelballDescriptorRead(QLowEnergyDescriptor,QByteArray)));
    connect(m_service, SIGNAL(descriptorWritten(QLowEnergyDescriptor,QByteArray)), this, SLOT(KlingelballDescriptorWritten(QLowEnergyDescriptor,QByteArray)));

    m_service->discoverDetails();
}

void KlingelballUI::KlingelballServiceStatechanged(QLowEnergyService::ServiceState serviceState){
    switch(serviceState){
    case QLowEnergyService::ServiceState::InvalidService:
        qDebug("invalid  Service");
        break;

    case QLowEnergyService::ServiceState::LocalService:
        qDebug("Local Service");
        break;

    case QLowEnergyService::ServiceState::RemoteService:
        qDebug("Remote Service");
        break;

    case QLowEnergyService::ServiceState::RemoteServiceDiscovered:
        qDebug("Remote Service discovered");
        AudioCharacteristic = new QLowEnergyCharacteristic(m_service->characteristic(*AudioCharacteristicUUID));
        m_service->writeCharacteristic(*AudioCharacteristic, QString("hi").toUtf8(), QLowEnergyService::WriteWithResponse);
        break;

    case QLowEnergyService::ServiceState::RemoteServiceDiscovering:
        qDebug("remote Service Discovering");
        break;
    }
}

void KlingelballUI::KlingelballServiceError(QLowEnergyService::ServiceError error){

    switch(error){
        case QLowEnergyService::ServiceError::NoError:
            qDebug("NoError");
        break;

    case QLowEnergyService::ServiceError::OperationError:
        qDebug("operationError");
        break;

    case QLowEnergyService::ServiceError::CharacteristicReadError:
        qDebug("CharacteristicReadError");
        break;

    case QLowEnergyService::ServiceError::CharacteristicWriteError:
        qDebug("characteristicWriteError");
        break;

    case QLowEnergyService::ServiceError::DescriptorReadError:
        qDebug("DescriptionReadError");
        break;

    case QLowEnergyService::ServiceError::DescriptorWriteError:
        qDebug("DescriptorWriteError");
        break;

    case QLowEnergyService::ServiceError::UnknownError:
        qDebug("UnknownError");
        break;
    }
}

void KlingelballUI::KlingelballCharacteristicRead(QLowEnergyCharacteristic characteristic, QByteArray data){}

void KlingelballUI::KlingelballCharacteristicWritten(QLowEnergyCharacteristic characteristic, QByteArray data){
    qDebug()<< "characteristicWritten";
    qDebug() << data.toStdString();
    printMessage("über. success!!");
}

void KlingelballUI::KlingelballCharacteristicChanged(QLowEnergyCharacteristic characteristic, QByteArray data){}

void KlingelballUI::KlingelballDescriptorRead(QLowEnergyDescriptor descriptor, QByteArray data){}

void KlingelballUI::KlingelballDescriptorWritten(QLowEnergyDescriptor descriptor, QByteArray data){}



