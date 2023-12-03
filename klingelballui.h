#ifndef KLINGELBALLUI_H
#define KLINGELBALLUI_H

#include <QMainWindow>
#include <QSoundEffect>
#include "QSize"
#include <QByteArray>
#include <QBuffer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QFile>
#include "EinstellungsProfil.h"
#include <QScroller>
#include <QTimer>
#include <QList>
#include <QScreen>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothServer>
#include <QBluetoothDeviceInfo>
#include "deviceinfo.h"
#include <qlowenergycontroller.h>
#include <QBluetoothPermission>

QT_BEGIN_NAMESPACE
namespace Ui { class KlingelballUI; }
QT_END_NAMESPACE

class KlingelballUI : public QMainWindow
{
    Q_OBJECT

public:
    KlingelballUI(QWidget *parent = nullptr);
    ~KlingelballUI();

public slots:
    void change_profile_selection();
    void update_profile_transmittion_state();

    void serviceDiscovered(QBluetoothUuid uuid);
    void serviceScanDone();
    void controllerError(QLowEnergyController::Error error);
    void deviceConnected();
    void deviceDisconnected();
    void KlingelballServiceStatechanged(QLowEnergyService::ServiceState serviceState);
    void KlingelballServiceError(QLowEnergyService::ServiceError error);
    void KlingelballCharacteristicRead(QLowEnergyCharacteristic characteristic, QByteArray data);
    void KlingelballCharacteristicWritten(QLowEnergyCharacteristic characteristic, QByteArray data);
    void KlingelballCharacteristicChanged(QLowEnergyCharacteristic characteristic, QByteArray data);
    void KlingelballDescriptorRead(QLowEnergyDescriptor descriptor, QByteArray data);
    void KlingelballDescriptorWritten(QLowEnergyDescriptor descriptor, QByteArray data);

private slots:
    void on_Bis_Frequ_valueChanged(int arg1);

    void on_Volume_valueChanged(int arg1);

    void on_Lightmode_checkBox_clicked();

    void on_Darkmode_checkBox_clicked();


    void on_FontSize_spinBox_valueChanged(int arg1);

    void on_profil_from_currentsettings_button_clicked();

    void on_new_profile_button_clicked();

    void on_new_profile_cancle_button_clicked();

    void on_delete_current_profile_button_clicked();

    void on_uebertragen_button_clicked();

    void on_searchKlingelball_clicked();

    void on_connectKlingelball_clicked();

private:
    Ui::KlingelballUI *ui;

    QSoundEffect effect;
    bool transmit_profile = false;

    QFont *dynamicSizeFont;
    QFont *testFont;

    void setup_UI();
    void setup_font();
    void setup_labels();
    void setup_buttons();
    void setup_spinbox();
    void setup_lineedit();

    void playSoundEffect(int Volume);

    void create_Profile(QString name, int volume, int freq_still, int freq_bew);
    void create_Profile_visualisation(EinstellungsProfil *profil);
    void destroy_Profile_visualisation(EinstellungsProfil *profil);
    QList<EinstellungsProfil *> *Profile_list;

    void set_transmit_profile(bool b);

    QRect rect = KlingelballUI::geometry();
    QScreen *screen;

    qreal height = qMax(rect.width(), rect.height());
    qreal width = qMin(rect.width(), rect.height());

    qreal dpi = KlingelballUI::logicalDpiX();


    /********************************************/

    QBluetoothUuid *KlingelballUUID = new QBluetoothUuid("4fafc201-1fb5-459e-8fcc-c5c9c331914b");

    QLowEnergyCharacteristic *AudioCharacteristic;
    QBluetoothUuid *AudioCharacteristicUUID = new QBluetoothUuid("4a78b8dd-a43d-46cf-9270-f6b750a717c8");

    QLowEnergyCharacteristic *LightCharacteristic;
    QBluetoothUuid *LightCharacteristicUUID = new QBluetoothUuid("99067788-c62b-489d-82a9-6cbec8a31d07");

    QLowEnergyCharacteristic *TestCharacteristic;
    QBluetoothUuid *TestCharacteristicUUID = new QBluetoothUuid("a47b99b4-3804-4411-b61c-50852ab7aa2d");

    QLowEnergyCharacteristic *OnOffCharacteristic;
    QBluetoothUuid *OnOffCharacteristicUUID = new QBluetoothUuid("beb5483e-36e1-4688-b7f5-ea07361b26a8");

    void printMessage (QString message);

    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    QLowEnergyController *m_controller;
    QLowEnergyService *m_service;

    bool KlingelballConnected = false;

    void startDeviceDiscovery();

    void addDevice(const QBluetoothDeviceInfo&);
    void ScanFinished();
    void ScanError(QBluetoothDeviceDiscoveryAgent::Error);

    void connectDevice(QBluetoothDeviceInfo currentdevice);

    void setupServiceDiscovery();




};
#endif // KLINGELBALLUI_H
