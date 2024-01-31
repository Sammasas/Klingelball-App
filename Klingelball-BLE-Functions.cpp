#include "klingelballui.h"
#include "ui_klingelballui.h"

void KlingelballUI::setupBLE(){

    deviceList = new QList<DeviceInfo *>;

    QBluetoothLocalDevice localDevice;
    if(localDevice.isValid()){
        localDevice.powerOn();
    }

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

void KlingelballUI::on_uebertragen_button_clicked()
{   
    if(remoteServiceDiscovered && KlingelballConnected && !m_service->characteristics().empty()){
        qDebug() << "writeCharacteristik";
        transmittionActive = true;
        ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                        "background-color: orange;}");
        setUebertragenButtonTextandStyle("Übertrage...", "QPushButton{background-color: orange}"
                                              "QPushButton::pressed{Background: #5b5b5b; border-radius: 20px;}");
        transmittionStatus = TransmitGeneralSettings;
        transmitSettings();

    }else{
        qDebug() << "Klingelball not connected or no remoteservice discovered";
    }

}

void KlingelballUI::transmitSettings (){
    switch(transmittionStatus){ //TODO: Timeout
        case TransmittionDone:
            printMessage("TransmittionDone");
            transmittionActive = false;
            ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                            "background-color: #00aa00;}");
            setUebertragenButtonTextandStyle("Übertragung fertig!", "QPushButton{background-color: #e50616;}"
                                                  " QPushButton::pressed{Background: #5b5b5b; border-radius: 20px;}");

            transmittionStatus = TransmitGeneralSettings;
            break;

        case TransmitGeneralSettings:
            printMessage("TransmitGeneralSettings");
            qDebug() <<"Case:" << QString::number(Setting::GeneralSettings);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::GeneralSettings,
                                                                                             ui->OnOff_Button->isChecked(),
                                                                                             0,
                                                                                             0),
                                       QLowEnergyService::WriteWithResponse);

            transmittionStatus = TransmitSoundFrequenzy;
            break;

        case TransmitSoundFrequenzy:
            printMessage("TransmitSoundFrequenzy");
            qDebug() <<"Case:" << QString::number(Setting::SoundFrequenzy);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::SoundFrequenzy,
                                                                                             ui->Lautstaerke->value(),
                                                                                             ui->Stillstehend_Ton_Freq->value(),
                                                                                             ui->Bewegend_Ton_Freq->value()),
                                       QLowEnergyService::WriteWithResponse);

            transmittionStatus = TransmitGeneralSound;
            break;

        case TransmitGeneralSound:
            printMessage("TransmitGeneralSound");
            qDebug() <<"Case:" << QString::number(Setting::GeneralSound);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::GeneralSound,
                                                                                                 1,
                                                                                                 ui->Stillstehend_Beep_Freq->value(),
                                                                                                 ui->Bewegend_Beep_Freq->value()),
                                           QLowEnergyService::WriteWithResponse);

            transmittionStatus = TransmitGeneralLight;
            break;

        case TransmitGeneralLight:
            printMessage("TransmitGeneralLight");
            qDebug() <<"Case:" << QString::number(Setting::GeneralLight);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::GeneralLight,
                                                                                                 ui->Heilligkeit->value(),
                                                                                                 0, //TODO: Implement Blinking lights
                                                                                                 0),
                                           QLowEnergyService::WriteWithResponse);

            transmittionStatus = TransmitLightColorStill;
            break;

        case TransmitLightColorStill:
            printMessage("TransmitLightColorStill");
            qDebug() <<"Case:" << QString::number(Setting::LightColorStill);
            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::LightColorStill,
                                                                                                 StillstehendSelectedColor().red(),
                                                                                                 StillstehendSelectedColor().green(),
                                                                                                 StillstehendSelectedColor().blue()),
                                           QLowEnergyService::WriteWithResponse);
            transmittionStatus = TransmitLightColorMoving;
            break;

        case TransmitLightColorMoving:
            printMessage("TransmitLightColorMoving");

            m_service->writeCharacteristic(m_service->characteristics().at(0), generateBytearray(Setting::LightColorMoving,
                                                                                                 BewegendSelectedColor().red(),
                                                                                                 BewegendSelectedColor().green(),
                                                                                                 BewegendSelectedColor().blue()),
                                           QLowEnergyService::WriteWithResponse);

            transmittionStatus = TransmittionDone;
            break;
        case TransmittionError:
            qWarning() << "TransmittionError";
            transmittionActive = false;
            ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                            "background-color: #e50616;}");
            setUebertragenButtonTextandStyle("Übertragen Error!", "QPushButton{background-color: #e50616;}"
                                                  " QPushButton::pressed{Background: #5b5b5b; border-radius: 20px;}");

            transmittionStatus = TransmitGeneralSettings;
            break;
    }
}


QByteArray KlingelballUI::generateBytearray(Setting s,uint8_t data1, uint8_t data2, uint8_t data3){
    QByteArray a;
    a.resize(4);
    a[0] = 0;
    a[1] = data1;
    a[2] = data2;
    a[3] = data3;

    a[0] = generatePruefziffer(a) + s*10;

    qDebug() << "Übertrage:" << QString::number(a[0])
            << QString::number(a[1])
            << QString::number(a[2])
            << QString::number(a[3]);
    return a;
}

char KlingelballUI::generatePruefziffer(QByteArray a){
  int pruef = 0;
  int length = sizeof(a)/sizeof(a[0]);

  for(int i = 1; i < 4; i++){  //prüfziffer berechnen
    qDebug() << i;
    if(i % 2){
      pruef += a[i] * 1;
      qDebug() << QString::number(a[i]);

    } else{ //gerade
        qDebug() << "gerade";
      pruef += a[i] * 3;
      qDebug() << QString::number(a[i]);

    }
  }
    qDebug() << QString::number(pruef);
  pruef = 9 - (pruef % 10);

  qDebug()<<"prueffziffer"<<QString::number(pruef);
 return pruef;
}


void KlingelballUI::on_searchKlingelball_clicked()
{
    if(KlingelballConnected){
        m_controller->disconnectFromDevice();
    }
    ui->searchKlingelball->setStyleSheet("QPushButton{"
                                         "background-color: orange;}");
    ui->UIDeviceList->clear();
    startDeviceDiscovery();
}

QColor KlingelballUI::StillstehendSelectedColor(){
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

void KlingelballUI::on_connectKlingelball_clicked()
{
    for (int i = 0; i < ui->UIDeviceList->count(); i++){
        if(ui->UIDeviceList->item(i)->isSelected()){
            m_deviceDiscoveryAgent->stop();
            connectDevice(deviceList->at(i)->getDevice());
        }else{
              delete ui->UIDeviceList->takeItem(i);
              deviceList->remove(i);
            }
    }

}


void KlingelballUI::on_disconnectKlingelball_clicked()
{
    if(KlingelballConnected){
        m_controller->disconnectFromDevice();
    }
}


void KlingelballUI::printMessage(QString message){
    ui->statusLabel->setText("Status: " + message);
    qDebug() << message;

}

void KlingelballUI::startDeviceDiscovery(){
#if QT_CONFIG(permissions)
    //! [permissions]
    QBluetoothPermission permission{};
    QLocationPermission Locationpermission {};
    permission.setCommunicationModes(QBluetoothPermission::Access);
    Locationpermission.setAvailability(QLocationPermission::WhenInUse);


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

    switch (qApp->checkPermission(Locationpermission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(Locationpermission, this, &KlingelballUI::startDeviceDiscovery);
        printMessage("request permission");
        return;
    case Qt::PermissionStatus::Denied:
        printMessage("Ble permission denied");
        return;
    case Qt::PermissionStatus::Granted:
        printMessage("permission granted");
        if(Locationpermission.availability())
        break; // proceed to search
    }
    //! [permissions]
#endif // QT_CONFIG(permissions)

    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    if(!m_deviceDiscoveryAgent->isActive()){
        qWarning()<< "discovery failed!";
        ui->searchKlingelball->setStyleSheet("QPushButton{"
                                             "background-color: #e50616;}");
    }
    printMessage("suchen... ");//TODO: if bluetooth isnt on message
}

void KlingelballUI::addDevice(const QBluetoothDeviceInfo &device){
    if(device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration){
        if(device.name() == "Klingelball" || device.name() == "EchoBall"){ //TODO Suche nach address
            deviceList->append(new DeviceInfo{device});
            ui->UIDeviceList->addItem(device.name());
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
        qWarning("No Error");
    break;
    case QBluetoothDeviceDiscoveryAgent::PoweredOffError:
        qWarning("Bluetooth turned off");
        break;
    case QBluetoothDeviceDiscoveryAgent::InputOutputError:
        qWarning("InOut Error");
        break;
    case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
        qWarning("InvalidAdapter");
        break;
    case QBluetoothDeviceDiscoveryAgent::UnsupportedDiscoveryMethod:
        qWarning("Error 4");
        break;
    case QBluetoothDeviceDiscoveryAgent::UnsupportedPlatformError:
        qWarning("Error 5");
        break;
    case QBluetoothDeviceDiscoveryAgent::LocationServiceTurnedOffError:
        qWarning("Error 6");
        break;
    case QBluetoothDeviceDiscoveryAgent::MissingPermissionsError:
        qWarning("Error 7");
        break;
    case QBluetoothDeviceDiscoveryAgent::UnknownError:
        qWarning("Unknown Error");
        break;
    }

}

void KlingelballUI::connectDevice(const QBluetoothDeviceInfo *currentdevice){
    qDebug()<< "connectDevice";
    m_controller = QLowEnergyController::createCentral(*currentdevice, this);

    connect(m_controller, SIGNAL(serviceDiscovered(QBluetoothUuid)), this, SLOT(serviceDiscovered(QBluetoothUuid)));
    connect(m_controller, SIGNAL(discoveryFinished()), this, SLOT(serviceScanDone()));
    connect(m_controller, SIGNAL(connected()), this, SLOT(deviceConnected()));
    connect(m_controller, SIGNAL(errorOccurred(QLowEnergyController::Error)), this, SLOT(controllerError(QLowEnergyController::Error)));
    connect(m_controller, SIGNAL(disconnected()), this, SLOT(deviceDisconnected()));

    /*QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, m_controller, &QLowEnergyController::connectToDevice);
    connect(m_controller, &QLowEnergyController::connected, t, &QTimer::stop);
    connect(m_controller, &QLowEnergyController::disconnected, t, &QTimer::stop);*/
    m_controller->connectToDevice();
    //t->start(100);
}

void KlingelballUI::serviceDiscovered(QBluetoothUuid uuid){
    qDebug() << "service discovered";

}

void KlingelballUI::serviceScanDone(){
    qDebug()<<"serviceScanDone";
    setupServiceDiscovery();
}

void KlingelballUI::controllerError(QLowEnergyController::Error error){
    printMessage("Error");
    switch(error){
        case QLowEnergyController::Error::ConnectionError:
            qWarning()<<"ConnectionError";
            printMessage("Disconnected");
            KlingelballConnected = false;
            remoteServiceDiscovered = false;

            for(int i = 0; i < ui->UIDeviceList->count(); i ++){
                if(ui->UIDeviceList->takeItem(i)->text() == m_controller->remoteName()){
                    ui->UIDeviceList->removeItemWidget(ui->UIDeviceList->takeItem(i));
                }
            }
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
    ui->connectKlingelball->setVisible(false);
    ui->OnOff_Button->setVisible(true);
    ui->disconnectKlingelball->setVisible(true);
    ui->batteryStatusProgressbar->setVisible(true);
    ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                    "background-color: orange;}");

    m_controller->discoverServices();
}

void KlingelballUI::deviceDisconnected(){
    printMessage("device disconnected");
    qDebug() << "device disconnected";
    delete m_controller;
    delete m_service;
    KlingelballConnected = false;
    remoteServiceDiscovered = false;

    ui->UIDeviceList->clear();
    ui->OnOff_Button->setVisible(false);
    ui->disconnectKlingelball->setVisible(false);
    ui->batteryStatusProgressbar->setVisible(false);
    ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                    "background-color: blue;}");
    setUebertragenButtonTextandStyle("Übertragen", "");
}

void KlingelballUI::setupServiceDiscovery(){
    qDebug()<<"setupServiceDiscovery";
    for(int i = 0; i < m_controller->services().length(); i++){
        qDebug()<< m_controller->services()[i];
    }

    m_service = m_controller->createServiceObject(m_controller->services().last());

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
        BatteryCharacteristic = new QLowEnergyCharacteristic(
                    m_service->characteristic(*BatteryCharacteristicUUID));
        qDebug()<<"setupServiceDiscovery:new QLowEnergyCharacteristic";

        DataCharacteristic = new QLowEnergyCharacteristic(
                    m_service->characteristic(*DataCharacteristicUUID));


        qDebug() << m_service->characteristics().length();

        for (int i = 0; i < m_service->characteristics().length(); i++){
            qDebug()<< m_service->characteristics()[i].uuid().toString();
        }
        printMessage("Charactersitics found!");
        ui->UIDeviceList->setStyleSheet("QListWidget::item::selected{"
                                        "background-color: #00aa00;}");

        readBatteryStatus(BatteryCharacteristic);

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
            printMessage("Write Error!");
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

void KlingelballUI::KlingelballCharacteristicRead(QLowEnergyCharacteristic characteristic, QByteArray data){

    qDebug() << "CharactersiticRead: " << characteristic.uuid().toString();

    for (int i = 0; i< 4; i++){
        qDebug()<< QString::number(data[i]);
    }

    if (characteristic.uuid() == QBluetoothUuid("4a78b8dd-a43d-46cf-9270-f6b750a717c8")){
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
    }else if (characteristic.uuid() == m_service->characteristics()[0].uuid()){
        qDebug() << "Reading data characteristic";
        if(data[0] == 1)
        transmitSettings();
        switch(data[0]){
            case 1:
                qDebug() << "Verfication successfull";
                transmitSettings();
                break;
            case 2:
                qDebug() << "Verfication failed";
                transmittionStatus = TransmittionError;
                transmitSettings();
                break;
            default:
                qDebug() << "Verfication failed";
                transmittionStatus = TransmittionError;
                transmitSettings();
                break;
        }
    }



}

void KlingelballUI::KlingelballCharacteristicWritten(QLowEnergyCharacteristic characteristic, QByteArray data){
    qDebug()<< "characteristicWritten";
    qDebug() << data;
    printMessage("über. success!!");

    if (transmittionActive){
        m_service->readCharacteristic(characteristic);
    }
}

void KlingelballUI::KlingelballCharacteristicChanged(QLowEnergyCharacteristic characteristic, QByteArray data){}

void KlingelballUI::KlingelballDescriptorRead(QLowEnergyDescriptor descriptor, QByteArray data){}

void KlingelballUI::KlingelballDescriptorWritten(QLowEnergyDescriptor descriptor, QByteArray data){}

void KlingelballUI::readBatteryStatus(QLowEnergyCharacteristic *c){
    if(m_service->characteristics().contains(*c))
        m_service->readCharacteristic(*c);
}

void KlingelballUI::gotBatteryStatus(int s){
    ui->batteryStatusProgressbar->setValue(s);
}

void KlingelballUI::setUebertragenButtonTextandStyle(QString text, QString style){
   ui->uebertragen_button->setText(text);
   ui->Uebertragen2->setText(text);
   ui->Uebtragen3->setText(text);

   ui->uebertragen_button->setStyleSheet(style);
   ui->Uebertragen2->setStyleSheet(style);
   ui->Uebtragen3->setStyleSheet(style);
}
