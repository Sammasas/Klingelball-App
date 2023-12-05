#include "klingelballui.h"
#include "ui_klingelballui.h"

void KlingelballUI::setupBLE(){

    KlingelballServiceUUID = new QBluetoothUuid("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
    AudioCharacteristicUUID = new QBluetoothUuid("4a78b8dd-a43d-46cf-9270-f6b750a717c8");
    LightCharacteristicUUID = new QBluetoothUuid("99067788-c62b-489d-82a9-6cbec8a31d07");

    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(15000);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &KlingelballUI::addDevice);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &KlingelballUI::ScanError);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &KlingelballUI::ScanFinished);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
            this, &KlingelballUI::ScanFinished);
}

void KlingelballUI::on_uebertragen_button_clicked()
{   
    if(remoteServiceDiscovered && KlingelballConnected){
        qDebug() << "writeCharacteristik";
        m_service->writeCharacteristic(*AudioCharacteristic, QString("hi").toUtf8(), QLowEnergyService::WriteWithResponse);
    }else{
        qDebug() << "Klingelball not connected or no remoteservice discovered";
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
        if(device.name() == "Klingelball"){
            /*DeviceInfo deviceinfo(device);
            deviceList->append(&deviceinfo);
            ui->UIDeviceList->addItem(device.name());*/
            printMessage("verbinden...");
            m_deviceDiscoveryAgent->stop();
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
    qDebug()<< "connectDevice";
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
            qWarning()<<"ConnectionError";
            break;
        case QLowEnergyController::Error::RssiReadError:
            qWarning()<<"RssiReadError";
            break;
        case QLowEnergyController::Error::UnknownError:
            qWarning()<<"UnknownError";
            break;

        case QLowEnergyController::Error::AdvertisingError:
            qWarning()<<"AdvertisingError";
            break;

        case QLowEnergyController::Error::AuthorizationError:
            qWarning()<<"AuthorizationError";
            break;

        case QLowEnergyController::Error::InvalidBluetoothAdapterError:
            qWarning()<<"InvalidBluetoothAdapterError";
            break;

        case QLowEnergyController::Error::MissingPermissionsError:
            qWarning()<<"MissingPermissionsError";
            break;

        case QLowEnergyController::Error::NetworkError:
            qWarning()<<"NetworkError";
            break;

        case QLowEnergyController::Error::NoError:
            qWarning()<<"NoError";
            break;

        case QLowEnergyController::Error::RemoteHostClosedError:
            qWarning()<<"RemoteHostClosedError";
            break;

        case QLowEnergyController::Error::UnknownRemoteDeviceError:
            qWarning()<<"UnknownRemoteDeviceError";
            break;

    }
}

void KlingelballUI::deviceConnected(){
    qDebug() << "device connected";
    printMessage("verbunden!");
    KlingelballConnected = true;
    m_controller->discoverServices();
}

void KlingelballUI::deviceDisconnected(){
    qDebug() << "device disconnected";
    delete m_controller;
    delete m_service;
    KlingelballConnected = false;
    remoteServiceDiscovered = false;
}

void KlingelballUI::setupServiceDiscovery(){
    qDebug()<<"setupServiceDiscovery";

    m_service = m_controller->createServiceObject(*KlingelballServiceUUID, this);

    connect(m_service, SIGNAL(stateChanged(QLowEnergyService::ServiceState)), this,
            SLOT(KlingelballServiceStatechanged(QLowEnergyService::ServiceState)));
    connect(m_service, SIGNAL(errorOccurred(QLowEnergyService::ServiceError)), this,
            SLOT(KlingelballServiceError(QLowEnergyService::ServiceError)));
    connect(m_service, SIGNAL(characteristicRead(QLowEnergyCharacteristic,QByteArray)), this,
            SLOT(KlingelballCharacteristicRead(QLowEnergyCharacteristic,QByteArray)));
    connect(m_service, SIGNAL(characteristicWritten(QLowEnergyCharacteristic,QByteArray)), this,
            SLOT(KlingelballCharacteristicWritten(QLowEnergyCharacteristic,QByteArray)));
    connect(m_service, SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)), this,
            SLOT(KlingelballCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));
    connect(m_service, SIGNAL(descriptorRead(QLowEnergyDescriptor,QByteArray)), this,
            SLOT(KlingelballDescriptorRead(QLowEnergyDescriptor,QByteArray)));
    connect(m_service, SIGNAL(descriptorWritten(QLowEnergyDescriptor,QByteArray)), this,
            SLOT(KlingelballDescriptorWritten(QLowEnergyDescriptor,QByteArray)));
    qDebug()<<"setupServiceDiscovery:conn done";


    //qDebug()<<"setupServiceDiscovery:new QLowEnergyCharacteristic";
    //m_service->discoverDetails();
    qDebug()<<"setupServiceDiscovery:exit";


}

void KlingelballUI::KlingelballServiceStatechanged(QLowEnergyService::ServiceState serviceState){
    switch(serviceState){
    case QLowEnergyService::ServiceState::InvalidService:
        qWarning("invalid  Service");
        break;

    case QLowEnergyService::ServiceState::LocalService:
        qDebug("Local Service");
        break;

    case QLowEnergyService::ServiceState::RemoteService:
        qDebug("Remote Service");
        break;

    case QLowEnergyService::ServiceState::RemoteServiceDiscovered:
        qDebug("Remote Service discovered");
        AudioCharacteristic = new QLowEnergyCharacteristic(
                    m_service->characteristic(*AudioCharacteristicUUID));
        qDebug()<<"setupServiceDiscovery:new QLowEnergyCharacteristic";

        LightCharacteristic = new QLowEnergyCharacteristic(
                    m_service->characteristic(*LightCharacteristicUUID));

        remoteServiceDiscovered = true;
        break;

    case QLowEnergyService::ServiceState::RemoteServiceDiscovering:
        qDebug("remote Service Discovering");
        break;
    }
}

void KlingelballUI::KlingelballServiceError(QLowEnergyService::ServiceError error){

    switch(error){
        case QLowEnergyService::ServiceError::NoError:
            qWarning("NoError");
            break;

        case QLowEnergyService::ServiceError::OperationError:
            qWarning("operationError");
            break;

        case QLowEnergyService::ServiceError::CharacteristicReadError:
            qWarning("CharacteristicReadError");
            break;

        case QLowEnergyService::ServiceError::CharacteristicWriteError:
            qWarning("characteristicWriteError");
            break;

        case QLowEnergyService::ServiceError::DescriptorReadError:
            qWarning("DescriptionReadError");
            break;

        case QLowEnergyService::ServiceError::DescriptorWriteError:
            qWarning("DescriptorWriteError");
            break;

        case QLowEnergyService::ServiceError::UnknownError:
            qWarning("UnknownError");
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



