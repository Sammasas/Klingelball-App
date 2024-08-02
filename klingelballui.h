/**********************************************/
//Filename: klingelballui.h
//Author: Samuel Zeillinger
//Created On: 30 September 2023 20:01
//Description: main ui class
/**********************************************/

#ifndef KLINGELBALLUI_H
#define KLINGELBALLUI_H

#include <QMainWindow>
#include <QSoundEffect>
#include "QSize"
#include <QByteArray>
#include <QBuffer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QAccessible>
#include <QAccessibleActionInterface>
#include <QAccessible>
#include <QAccessibleWidget>
#include <QAccessibleInterface>
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
#include <QFontDatabase>
#include <QStyleHints>
#include <QFontDialog>
#include <QSettings>
#include <QListWidgetItem>
#include <QApplication>



#ifdef Q_OS_ANDROID
#include <QJniObject>
#include <jni.h>
#endif

#ifdef Q_OS_IOS
#include "iOSSettings.h"
#endif


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
    
    
private:
    enum SettingTransmitStatus{TransmitGeneralSettings,
                 TransmitSoundFrequenzy,
                 TransmitGeneralSound,
                 TransmitLightColorStill,
                 TransmitLightColorMoving,
                 TransmitGeneralLight,
                 TransmittionDone,
                 TransmittionError};
    SettingTransmitStatus transmittionStatus = TransmitGeneralSettings;



private slots:

    void on_Lightmode_checkBox_clicked();

    void on_Darkmode_checkBox_clicked();

    void on_profil_from_currentsettings_button_clicked();

    void on_new_profile_button_clicked();

    void on_new_profile_cancle_button_clicked();

    void on_delete_current_profile_button_clicked();

    void on_searchKlingelball_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_disconnectKlingelball_clicked();

    void on_OnOff_Button_toggled(bool checked);

    void transmitSettings(SettingTransmitStatus transStat);

    void gotBatteryStatus(int s);

    void on_colorSchemeChanged(Qt::ColorScheme scheme);

    void on_Lautstaerke_valueChanged(int arg1);

    void on_Stillstehend_Beep_Freq_valueChanged(int arg1);

    void on_Bewegend_Beep_Freq_valueChanged(int arg1);

    void updateAccessibleDesciption();

    void on_pause_button_clicked();

    void on_transmitGeneralSettings(){transmitSettings(SettingTransmitStatus::TransmitGeneralSettings);};
    void on_transmitSoundFrequenzy(){transmitSettings(SettingTransmitStatus::TransmitSoundFrequenzy);};
    void on_transmitGeneralSound(){transmitSettings(SettingTransmitStatus::TransmitGeneralSound);};
    void on_transmitLightColorStill(){transmitSettings(SettingTransmitStatus::TransmitLightColorStill);};
    void on_transmitLightColorMoving(){transmitSettings(SettingTransmitStatus::TransmitLightColorMoving);};
    void on_transmitGeneralLight(){transmitSettings(SettingTransmitStatus::TransmitGeneralLight);};

    void on_UIDeviceList_itemClicked(QListWidgetItem *item);

    void on_buttonGroupToggled(QAbstractButton *button, bool checked);

Q_SIGNALS:
    void BatteryStatusRead(int);


private:

    void printMessage(QString message);

    Ui::KlingelballUI *ui;

    bool transmit_profile = false;

    QFont *dynamicSizeFont;
    QFont *SmallerdynamicSizeFont;

    void setup_UI();
    void setup_fontAndroid(float fontScale);
    void setup_fontiOS(int pointSize);
    void setup_labels();
    void setup_buttons();
    void setup_spinbox();
    void setup_lineedit();
    void setup_ButtonGroup();

    float getfontScalefrompointSize(int pointSize);

    void create_Profile(QString name, int volume, int freq_still, int freq_bew);
    void create_Profile_visualisation(EinstellungsProfil *profil);
    void destroy_Profile_visualisation(EinstellungsProfil *profil);
    QList<EinstellungsProfil *> *Profile_list;

    void set_transmit_profile(bool b);

    /********************************************/

    QBluetoothUuid *KlingelballServiceUUID;

    QLowEnergyCharacteristic *BatteryCharacteristic;
    QBluetoothUuid *BatteryCharacteristicUUID;

    QLowEnergyCharacteristic *DataCharacteristic;
    QBluetoothUuid *DataCharacteristicUUID;

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

    void transmitAllSettings();

    enum Setting{GeneralSettings,
                 SoundFrequenzy,
                 GeneralSound,
                 LightColorStill,
                 LightColorMoving,
                 GeneralLight};

    

    enum ConnectionStatus{Disconnected,
                         Connecting,
                         Connected,
                         Transmitting};

    bool transmittionActive = false;



    QByteArray generateBytearray(Setting s,uint8_t data1, uint8_t data2, uint8_t data3);
    char generatePruefziffer (QByteArray a);

    QColor StillstehendSelectedColor();
    QColor BewegendSelectedColor();

    void readBatteryStatus(QLowEnergyCharacteristic *c);

    QButtonGroup *stillstehendColorSelectionButtonGroup;
    QButtonGroup *bewegendColorSelectionButtonGroup;
    bool stillstehendButtonGroupOneSelected = false;
    bool bewegendButtonGroupOneSelected = false;
    int stillstehendButtonGroupSelectedID = 0;
    int bewegendButtonGroupSelectedID = 0;

    QString RadioButtonCommonStyleDark = "QRadioButton{"
                                         "background-color: none;"
                                         "margin-top: 10px;"
                                         "margin-bottom: 10px;"
                                         "margin-left: 10px;"
                                         "margin-right: 10px;}"
                                         "QRadioButton::indicator:checked"
                                     "{border: 2px solid white;}"
                                     "QRadioButton::indicator:unchecked{"
                                     "border: 2px solid #868686;}";

    QString RadioButtonCommonStyleLight = "QRadioButton{"
                                          "background-color: none;"
                                          "margin-top: 10px;"
                                          "margin-bottom: 10px;"
                                          "margin-left: 10px;"
                                          "margin-right: 10px;} "
                                    "QRadioButton::indicator:checked"
                                     "{border: 2px solid black;} "
                                     "QRadioButton::indicator:unchecked{"
                                     "border: 2px solid #868686;} ";

    QString RadioButtonColor1 = "QRadioButton::indicator{"
                                 "background-color: white;"
                                 "width: 40px;height: 40px;"
                                 "border: 2px solid #868686;"
                                 "border-radius: 20px;} ";

    QString RadioButtonColor2 = "QRadioButton::indicator{"
                                 "background-color: red;"
                                 "width: 40px;height: 40px;"
                                 "border: 2px solid #868686;"
                                 "border-radius: 20px;} ";
    QString RadioButtonColor3 = "QRadioButton::indicator{"
                                 "background-color: blue;"
                                 "width: 40px;height: 40px;"
                                 "border: 2px solid #868686;"
                                 "border-radius: 20px;} ";
    QString RadioButtonColor4 = "QRadioButton::indicator{"
                                 "background-color: rgb(0, 255, 0);"
                                 "width: 40px;height: 40px;"
                                 "border: 2px solid #868686;"
                                 "border-radius: 20px;} ";
    QString RadioButtonColor5 = "QRadioButton::indicator{"
                                 "background-color: yellow;"
                                 "width: 40px;height: 40px;"
                                 "border: 2px solid #868686;"
                                 "border-radius: 20px;} ";
    float *fontScale;

    QSettings *settings;





};

#endif // KLINGELBALLUI_H
