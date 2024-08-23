/**********************************************/
//Filename: Klingelball-BLE-Functions.cpp
//Author: Samuel Zeillinger
//Created On: 1 December 2023 18:31
//Description: Every function related to Bluetooth Low Energy
/**********************************************/



#include "klingelballui.h"
#include "ui_klingelballui.h"

void KlingelballUI::setupBLE(){

    deviceList = new QList<DeviceInfo *>;

//Powers on Bluetooth on Android devices
#ifdef Q_OS_ANDROID
    QBluetoothLocalDevice localDevice;
    if(localDevice.isValid()){
        localDevice.powerOn();
        qDebug() << "Device powered on";
    }else
        qDebug()<< "Device not valid";
#endif

    KlingelballServiceUUID = new QBluetoothUuid("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
    BatteryCharacteristicUUID = new QBluetoothUuid("4a78b8dd-a43d-46cf-9270-f6b750a717c8");
    DataCharacteristicUUID = new QBluetoothUuid("99067788-c62b-489d-82a9-6cbec8a31d07");

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

    connect(this, SIGNAL(BatteryStatusRead(int)), this, SLOT(gotBatteryStatus(int)));
}

void KlingelballUI::transmitSettings (SettingTransmitStatus transStat){
    if(!remoteServiceDiscovered || !KlingelballConnected || m_service->characteristics().empty()){
        return;
    }

    switch(transStat){ //TODO: Timeout & Error doesnt stop transmittion
        case TransmittionDone:
            printMessage("TransmittionDone");
            transmittionActive = false;
            ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                            "background-color: #00aa00;}");
            break;

        case TransmitGeneralSettings:
            printMessage("TransmitGeneralSettings");
            qDebug() <<"Case:" << QString::number(Setting::GeneralSettings);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::GeneralSettings,
                                                                                             ui->OnOff_Button->isChecked(),
                                                                                             0,
                                                                                             0),
                                       QLowEnergyService::WriteWithResponse);
            readBatteryStatus(BatteryCharacteristic);
            break;

        case TransmitSoundFrequenzy:
            printMessage("TransmitSoundFrequenzy");
            qDebug() <<"Case:" << QString::number(Setting::SoundFrequenzy);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::SoundFrequenzy,
                                                                                             ui->Lautstaerke->value(),
                                                                                             ui->Stillstehend_Ton_Freq->value(),
                                                                                             ui->Bewegend_Ton_Freq->value()),
                                       QLowEnergyService::WriteWithResponse);
            readBatteryStatus(BatteryCharacteristic);
            break;

        case TransmitGeneralSound:
            printMessage("TransmitGeneralSound");
            qDebug() <<"Case:" << QString::number(Setting::GeneralSound);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::GeneralSound,
                                                                                                 1,
                                                                                                 ui->Stillstehend_Beep_Freq->value(),
                                                                                                 ui->Bewegend_Beep_Freq->value()),
                                           QLowEnergyService::WriteWithResponse);
            readBatteryStatus(BatteryCharacteristic);
            break;

        case TransmitGeneralLight:
            printMessage("TransmitGeneralLight");
            qDebug() <<"Case:" << QString::number(Setting::GeneralLight);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::GeneralLight,
                                                                                                 ui->Helligkeit->value(),
                                                                                                 0, //TODO: Implement Blinking lights
                                                                                                 0),
                                           QLowEnergyService::WriteWithResponse);
            readBatteryStatus(BatteryCharacteristic);
            break;

        case TransmitLightColorStill:
            printMessage("TransmitLightColorStill");
            qDebug() <<"Case:" << QString::number(Setting::LightColorStill);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::LightColorStill,
                                                                                                 StillstehendSelectedColor().red(),
                                                                                                 StillstehendSelectedColor().green(),
                                                                                                 StillstehendSelectedColor().blue()),
                                           QLowEnergyService::WriteWithResponse);
            readBatteryStatus(BatteryCharacteristic);
            break;

        case TransmitLightColorMoving:
            printMessage("TransmitLightColorMoving");

            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::LightColorMoving,
                                                                                                 BewegendSelectedColor().red(),
                                                                                                 BewegendSelectedColor().green(),
                                                                                                 BewegendSelectedColor().blue()),
                                           QLowEnergyService::WriteWithResponse);
            readBatteryStatus(BatteryCharacteristic);
            break;
        case TransmittionError:
            qWarning() << "TransmittionError";
            transmittionActive = false;
            ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                            "background-color: #e50616;}");

            transmittionStatus = TransmitGeneralSettings;
            break;
    }
}


QByteArray KlingelballUI::generateBytearray(Setting s,uint8_t data1, uint8_t data2, uint8_t data3){
    //Generates byte array ready for transmittion
    QByteArray a;
    a.resize(4);
    qDebug() << "Daten:" << QString::number(s)
             << QString::number(data1)
             << QString::number(data2)
             << QString::number(data3);

    a[0] = 0;
    a[1] = data1;
    a[2] = data2;
    a[3] = data3;

    a[0] = generatePruefziffer(a) + s*10;

    qDebug() << "Übertrage:" << QString::number(a[0])
             << QString::number((uint8_t)a[1])
            << QString::number((uint8_t)a[2])
            << QString::number((uint8_t)a[3]);

    return a;
}

char KlingelballUI::generatePruefziffer(QByteArray a){
  unsigned int pruef = 0;

  for(int i = 1; i < 4; i++){
    if(i % 2){
          pruef += (uint8_t)a[i] * 1;
        qDebug() << QString::number(pruef);

    } else{ //gerade
      pruef += (uint8_t)a[i] * 3;
        qDebug() << QString::number(pruef);
    }
  }
  pruef = 9 - (pruef % 10);
  qDebug()<<"prueffziffer"<<QString::number(pruef);
  return pruef;
}


void KlingelballUI::on_searchKlingelball_clicked()
{
    //starts new search for device, disconnects from connected device
    if(KlingelballConnected){
        m_controller->disconnectFromDevice();
    }

    ui->UIDeviceList->clear();
    ui->UIDeviceList->setAccessibleName(tr("Verfügbare Klingelbälle Liste,") + QString::number(ui->UIDeviceList->count()) + tr("verfügbar"));
    startDeviceDiscovery();
}

QColor KlingelballUI::StillstehendSelectedColor(){
    //returns color value based on selected color
    if(ui->Stillstehend_Farbe1->isChecked())
        return QColor(255, 255, 255);
    if(ui->Stillstehend_Farbe2->isChecked())
        return QColor(255, 0, 0);
    if(ui->Stillstehend_Farbe3->isChecked())
        return QColor(0, 0, 255);
    if(ui->Stillstehend_Farbe4->isChecked())
        return QColor(0, 255, 0);
    if(ui->Stillstehend_Farbe5->isChecked())
        return QColor(255, 255, 0);
    else
        return QColor(0, 0, 0);
}

QColor KlingelballUI::BewegendSelectedColor(){
    //returns color value based on selected color
    if(ui->Bewegend_Farbe1->isChecked())
        return QColor(255, 255, 255);
    if(ui->Bewegend_Farbe2->isChecked())
        return QColor(255, 0, 0);
    if(ui->Bewegend_Farbe3->isChecked())
        return QColor(0, 0, 255);
    if(ui->Bewegend_Farbe4->isChecked())
        return QColor(0, 255, 0);
    if(ui->Bewegend_Farbe5->isChecked())
        return QColor(255, 255, 0);
    else
        return StillstehendSelectedColor();
}

void KlingelballUI::on_disconnectKlingelball_clicked()
{
    if(KlingelballConnected){
        m_controller->disconnectFromDevice();
    }
}

void KlingelballUI::printMessage(QString message){
    
    qWarning() << message;

}

void KlingelballUI::startDeviceDiscovery(){

    //get permission from user to use Bluetooth
#if QT_CONFIG(permissions)
    //! [permissions]
    QBluetoothPermission permission{};
    permission.setCommunicationModes(QBluetoothPermission::Access);


    switch (qApp->checkPermission(permission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(permission, this, &KlingelballUI::startDeviceDiscovery);
        printMessage("request permission");
        return;
    case Qt::PermissionStatus::Denied:
        printMessage("Ble permission denied");
        return;
    case Qt::PermissionStatus::Granted:
        printMessage("permission granted");
        break; // proceed to search
    }

    //Get permission to use location (Android Bluetooth only works with location turned on)
#ifdef Q_OS_ANDROID
    QLocationPermission Locationpermission {};
    Locationpermission.setAvailability(QLocationPermission::WhenInUse);
    switch (qApp->checkPermission(Locationpermission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(Locationpermission, this, &KlingelballUI::startDeviceDiscovery);
        printMessage("request permission");
        return;
    case Qt::PermissionStatus::Denied:
        printMessage("Location permission denied");
        return;
    case Qt::PermissionStatus::Granted:
        printMessage("permission granted");
        if(Locationpermission.availability())
            break; // proceed to search
    }
#endif
    //! [permissions]
#endif // QT_CONFIG(permissions)

    //start device discovery and set UI to show if search is active or failed
    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    if(!m_deviceDiscoveryAgent->isActive()){
        qWarning()<< "discovery failed!";
        ui->searchKlingelball->setStyleSheet("QPushButton{"
                                             "background-color: #e50616;}");
    }else{
        ui->searchKlingelball->setStyleSheet("QPushButton{"
                                             "background-color: orange;}");
    }
   //TODO: if bluetooth isnt on message
}

void KlingelballUI::addDevice(const QBluetoothDeviceInfo &device){
    if(device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration){
        if(device.name().contains("Klingelball")){
            //Add device to deviceList and UI devicelist
            deviceList->append(new DeviceInfo{device});
            ui->UIDeviceList->addItem(device.name());

            ui->UIDeviceList->setDisabled(true);
            ui->UIDeviceList->hide();
            ui->UIDeviceList->show();
            ui->UIDeviceList->setDisabled(false);

            ui->UIDeviceList->setAccessibleName(tr("Verfügbare Klingelbälle Liste,") + QString::number(ui->UIDeviceList->count()) + tr("verfügbar"));
             
        }
    }
}

void KlingelballUI::ScanFinished(){
    ui->searchKlingelball->setStyleSheet("QPushButton{"
                                         "background-color: #e50616;}");
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

void KlingelballUI::connectDevice(const QBluetoothDeviceInfo *currentdevice){
    qDebug()<< "connectDevice";
    ui->disconnectKlingelball->setDisabled(true);
    ui->searchKlingelball->setDisabled(true);
    m_controller = QLowEnergyController::createCentral(*currentdevice, this);

    connect(m_controller, SIGNAL(serviceDiscovered(QBluetoothUuid)), this, SLOT(serviceDiscovered(QBluetoothUuid)));
    connect(m_controller, SIGNAL(discoveryFinished()), this, SLOT(serviceScanDone()));
    connect(m_controller, SIGNAL(connected()), this, SLOT(deviceConnected()));
    connect(m_controller, SIGNAL(errorOccurred(QLowEnergyController::Error)), this, SLOT(controllerError(QLowEnergyController::Error)));
    connect(m_controller, SIGNAL(disconnected()), this, SLOT(deviceDisconnected()));


    m_controller->connectToDevice();

}

void KlingelballUI::serviceDiscovered(QBluetoothUuid uuid){
    Q_UNUSED(uuid);
    qDebug() << "service discovered";

}

void KlingelballUI::serviceScanDone(){
    qDebug()<<"serviceScanDone";
    setupServiceDiscovery();
}

void KlingelballUI::controllerError(QLowEnergyController::Error error){
    switch(error){
        case QLowEnergyController::Error::ConnectionError:
            printMessage("ConnectionError");
            printMessage("Disconnected");
            KlingelballConnected = false;
            remoteServiceDiscovered = false;

            for(int i = 0; i < ui->UIDeviceList->count(); i++){
                if(ui->UIDeviceList->takeItem(i)->text() == m_controller->remoteName()){
                    ui->UIDeviceList->removeItemWidget(ui->UIDeviceList->takeItem(i));
                    ui->UIDeviceList->setAccessibleName(tr("Verfügbare Klingelbälle Liste,") + QString::number(ui->UIDeviceList->count()) + tr("verfügbar"));
                }
            }
            break;
        case QLowEnergyController::Error::RssiReadError:
            printMessage("RssiReadError");
            break;
        case QLowEnergyController::Error::UnknownError:
            printMessage("UnknownError");
            break;

        case QLowEnergyController::Error::AdvertisingError:
            printMessage("AdvertisingError");
            break;

        case QLowEnergyController::Error::AuthorizationError:
            printMessage("AuthorizationError");
            break;

        case QLowEnergyController::Error::InvalidBluetoothAdapterError:
            printMessage("InvalidBluetoothAdapterError");
            break;

        case QLowEnergyController::Error::MissingPermissionsError:
            printMessage("MissingPermissionsError");
            break;

        case QLowEnergyController::Error::NetworkError:
            printMessage("NetworkError");
            break;

        case QLowEnergyController::Error::NoError:
            printMessage("NoError");
            break;

        case QLowEnergyController::Error::RemoteHostClosedError:
            printMessage("RemoteHostClosedError");
            break;

        case QLowEnergyController::Error::UnknownRemoteDeviceError:
            printMessage("UnknownRemoteDeviceError");
            break;

    }
}

void KlingelballUI::deviceConnected(){
    //Show widgets to controll connected device
    qDebug() << "device connected";
    KlingelballConnected = true;
    ui->OnOff_Button->setVisible(true);
    ui->disconnectKlingelball->setVisible(true);


    //Discover services from connected device and set UI to show discovery is active
    ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                    "background-color: orange;}");

    m_controller->discoverServices();
}

void KlingelballUI::deviceDisconnected(){
    qDebug() << "device disconnected";
    delete m_controller;
    delete m_service;
    KlingelballConnected = false;
    remoteServiceDiscovered = false;

    //Hide all widgets to controll connected device and set UI to show device is disconnected
    ui->UIDeviceList->clear();
    ui->UIDeviceList->setAccessibleName("Verfügbare Klingelbälle Liste," + QString::number(ui->UIDeviceList->count()) + "verfügbar");
    ui->OnOff_Button->setVisible(false);
    ui->disconnectKlingelball->setVisible(false);
    ui->batteryStatusProgressbar->setVisible(false);
    ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                    "background-color: blue;}");
}

void KlingelballUI::setupServiceDiscovery(){
    qDebug()<<"setupServiceDiscovery";
    for(int i = 0; i < m_controller->services().length(); i++){
        qDebug()<< m_controller->services().at(i);//TODO: [i] -> .at(i)

    }

    foreach (QBluetoothUuid s, m_controller->services()) {
        if (s == *KlingelballServiceUUID)
            m_service = m_controller->createServiceObject(s);
    }

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

    m_service->discoverDetails();

    qDebug()<<"setupServiceDiscovery:exit";


}

void KlingelballUI::KlingelballServiceStatechanged(QLowEnergyService::ServiceState serviceState){
    switch(serviceState){
    case QLowEnergyService::ServiceState::InvalidService:
        printMessage("invalid  Service");
        break;

    case QLowEnergyService::ServiceState::LocalService:
        qDebug("Local Service");
        break;

    case QLowEnergyService::ServiceState::RemoteService:
        qDebug("Remote Service");
        break;

    case QLowEnergyService::ServiceState::RemoteServiceDiscovered:
        qDebug("Remote Service discovered");
        BatteryCharacteristic = new QLowEnergyCharacteristic(
                    m_service->characteristic(*BatteryCharacteristicUUID));
        qDebug()<<"setupServiceDiscovery:new QLowEnergyCharacteristic";

        DataCharacteristic = new QLowEnergyCharacteristic(
                    m_service->characteristic(*DataCharacteristicUUID));


        qDebug() << m_service->characteristics().length();

        for (int i = 0; i < m_service->characteristics().length(); i++){
            qDebug()<< m_service->characteristics().at(i).uuid().toString();
        }
        printMessage("Charactersitics found!");
        ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                        "background-color: #00aa00;}");

        remoteServiceDiscovered = true;

        transmitAllSettings();

        ui->UIDeviceList->currentItem()->setText(ui->UIDeviceList->currentItem()->text() + " - verbunden");
        ui->disconnectKlingelball->setDisabled(false);
        ui->searchKlingelball->setDisabled(false);
        break;

    case QLowEnergyService::ServiceState::RemoteServiceDiscovering:
        qDebug("remote Service Discovering");
        break;
    }
}

void KlingelballUI::KlingelballServiceError(QLowEnergyService::ServiceError error){

    switch(error){
        case QLowEnergyService::ServiceError::NoError:
            printMessage("NoError");
            break;

        case QLowEnergyService::ServiceError::OperationError:
            printMessage("operationError");
            break;

        case QLowEnergyService::ServiceError::CharacteristicReadError:
            printMessage("CharacteristicReadError");
            break;

        case QLowEnergyService::ServiceError::CharacteristicWriteError:
            printMessage("characteristicWriteError");
            printMessage("Write Error!");
            break;

        case QLowEnergyService::ServiceError::DescriptorReadError:
            printMessage("DescriptionReadError");
            break;

        case QLowEnergyService::ServiceError::DescriptorWriteError:
            printMessage("DescriptorWriteError");
            break;

        case QLowEnergyService::ServiceError::UnknownError:
            printMessage("UnknownError");
            break;
    }
}

void KlingelballUI::KlingelballCharacteristicRead(QLowEnergyCharacteristic characteristic, QByteArray data){

    qDebug() << "CharactersiticRead: " << characteristic.uuid().toString();

    for (int i = 0; i< 4; i++){
        qDebug()<< QString::number(data[i]);
    }
    //Get battery status
    if (characteristic.uuid() == *BatteryCharacteristicUUID){
        qDebug() << "Reading Battery charactersitic";
        if(data[0]%10 == generatePruefziffer(data)){
            switch(data[0]/10){
                case 6:
                    qDebug()<<"BatteryStatusRead";
                    emit BatteryStatusRead(data[1]);

                    break;
                default:
                    qWarning() << "No valid data found";
                    break;
            }
        }else
            qWarning() <<"Pruefziffer not valid";
    }else if (characteristic.uuid() == *DataCharacteristicUUID){
        //verify successfull transmittion
        qDebug() << "Reading data characteristic";
        switch(data[0]){
            case 1:
                qDebug() << "Verfication successfull";
                transmitSettings(SettingTransmitStatus::TransmittionDone);
                break;
            case 2:
                qDebug() << "Verfication failed";
                transmittionStatus = TransmittionError;
                transmitSettings(SettingTransmitStatus::TransmittionError);
                break;
            default:
                qDebug() << "Verfication failed";
                transmittionStatus = TransmittionError;
                transmitSettings(SettingTransmitStatus::TransmittionError);
                break;
        }
    }
}

void KlingelballUI::KlingelballCharacteristicWritten(QLowEnergyCharacteristic characteristic, QByteArray data){
    qDebug()<< "characteristicWritten";
    qDebug() << QString::number(data[0])
               << QString::number((uint8_t)data[1])
               << QString::number((uint8_t)data[2])
               << QString::number((uint8_t)data[3]);
    printMessage("über. success!!");

    if (transmittionActive){
        m_service->readCharacteristic(*DataCharacteristic);
    }
}

void KlingelballUI::KlingelballCharacteristicChanged(QLowEnergyCharacteristic characteristic, QByteArray data){Q_UNUSED(characteristic); Q_UNUSED(data)}

void KlingelballUI::KlingelballDescriptorRead(QLowEnergyDescriptor descriptor, QByteArray data){Q_UNUSED(descriptor); Q_UNUSED(data)}

void KlingelballUI::KlingelballDescriptorWritten(QLowEnergyDescriptor descriptor, QByteArray data){Q_UNUSED(descriptor); Q_UNUSED(data)}

void KlingelballUI::readBatteryStatus(QLowEnergyCharacteristic *c){
    if(m_service->characteristics().contains(*c))
        m_service->readCharacteristic(*c);
}

void KlingelballUI::gotBatteryStatus(int s){
    qWarning() << "Batterystand:" << QString::number(s);
   if (s == -1 || s == 255){
        qWarning() << "batteryStatus noshow";
        ui->batteryStatusProgressbar->hide();
    }else{
        ui->batteryStatusProgressbar->show();
        qWarning() << "battery status show!!";
        s >= 100 ? ui->batteryStatusProgressbar->setValue(100) : ui->batteryStatusProgressbar->setValue(s);
    }


}

void KlingelballUI::transmitAllSettings(){
    qDebug()<< "transmitAllSettings";
    on_transmitGeneralSettings();
    on_transmitSoundFrequenzy();
    on_transmitGeneralSound();
    on_transmitLightColorStill();
    on_transmitLightColorMoving();
    on_transmitGeneralLight();
}
