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
#include <QBluetoothLocalDevice>
#include <QButtonGroup>
#include <QSettings>

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
    void stillstehendButtonGroupClicked(QAbstractButton *button);
    void bewegendButtonGroupClicked(QAbstractButton *button);


private slots:
    void on_Bis_Frequ_valueChanged(int arg1);

    void on_Volume_valueChanged(int arg1);

    void on_Lightmode_checkBox_clicked();

    void on_Darkmode_checkBox_clicked();

    void on_profil_from_currentsettings_button_clicked();

    void on_new_profile_button_clicked();

    void on_new_profile_cancle_button_clicked();

    void on_delete_current_profile_button_clicked();

    void on_uebertragen_button_clicked();

    void on_searchKlingelball_clicked();

    void on_connectKlingelball_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_disconnectKlingelball_clicked();

    //void on_pushButton_toggled(bool checked);

    void on_OnOff_Button_toggled(bool checked);

    void on_UIDeviceList_currentRowChanged(int currentRow);

    void transmitSettings();

private:
    Ui::KlingelballUI *ui;

    QSoundEffect effect;
    bool transmit_profile = false;

    QFont *dynamicSizeFont;
    QFont *SmallerdynamicSizeFont;

    void setup_UI();
    void setup_font();
    void setup_labels();
    void setup_buttons();
    void setup_spinbox();
    void setup_lineedit();
    void setup_ButtonGroup();

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

    QBluetoothUuid *KlingelballServiceUUID;

    QLowEnergyCharacteristic *AudioCharacteristic;
    QBluetoothUuid *AudioCharacteristicUUID;

    QLowEnergyCharacteristic *LightCharacteristic;
    QBluetoothUuid *LightCharacteristicUUID;

    QLowEnergyCharacteristic *TestCharactersitic;
    QBluetoothUuid *TestCharacteristicUUID;

    QLowEnergyCharacteristic *Test2Characteristic;
    QBluetoothUuid *Test2CharacteristicUUID;

    /*QLowEnergyCharacteristic *TestCharacteristic;
    QBluetoothUuid *TestCharacteristicUUID = new QBluetoothUuid("a47b99b4-3804-4411-b61c-50852ab7aa2d");

    QLowEnergyCharacteristic *OnOffCharacteristic;
    QBluetoothUuid *OnOffCharacteristicUUID = new QBluetoothUuid("beb5483e-36e1-4688-b7f5-ea07361b26a8");
    */
    void printMessage (QString message);

    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    QLowEnergyController *m_controller;
    QLowEnergyService *m_service;

    bool KlingelballConnected = false;
    bool remoteServiceDiscovered = false;

    void startDeviceDiscovery();

    void addDevice(const QBluetoothDeviceInfo&);
    void ScanFinished();
    void ScanError(QBluetoothDeviceDiscoveryAgent::Error);

    void connectDevice(const QBluetoothDeviceInfo *currentdevice);

    void setupServiceDiscovery();
    void setupBLE();

    QList<DeviceInfo *> *deviceList;
    DeviceInfo *ptrDevinfo;


    enum Setting{GeneralSettings,
                 SoundFrequenzy,
                 GeneralSound,
                 LightColorStill,
                 LightColorMoving,
                 GeneralLight};

    enum SettingTransmitStatus{TransmitGeneralSettings,
                 TransmitSoundFrequenzy,
                 TransmitGeneralSound,
                 TransmitLightColorStill,
                 TransmitLightColorMoving,
                 TransmitGeneralLight,
                 TransmittionDone};
    SettingTransmitStatus transmittionStatus = TransmitGeneralSettings;

    enum ConnectionStatus{Disconnected,
                         Connecting,
                         Connected,
                         Transmitting};

    bool transmittionActive = false;



    QByteArray generateBytearray(Setting s,uint8_t data1, uint8_t data2, uint8_t data3);
    char generatePruefziffer (QByteArray a);

    QColor StillstehendSelectedColor();
    QColor BewegendSelectedColor();

    QButtonGroup *stillstehendColorSelectionButtonGroup;
    QButtonGroup *bewegendColorSelectionButtonGroup;
    bool stillstehendButtonGroupOneSelected = false;
    bool bewegendButtonGroupOneSelected = false;
    int stillstehendButtonGroupSelectedID = 0;
    int bewegendButtonGroupSelectedID = 0;

    QTimer *timer;

};
#endif // KLINGELBALLUI_H
