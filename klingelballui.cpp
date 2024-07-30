/**********************************************/
//Filename: Klingelball.cpp
//Author: Samuel Zeillinger
//Created On: 30 ‎September ‎2023 ‏‎20:01
//Description: klingelballui constructor
/**********************************************/

#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(2);
    setup_UI();
    setupBLE();

//Cycle through tabs to ensure proper resizing
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);

    ui->Sound_tabWidget->setCurrentIndex(0);

//Setup Profile tab
//Not used in this version of the project (V1.0)
    Profile_list = new QList<EinstellungsProfil *>;
    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );

    setupBLE();
    ui->statusLabel->setVisible(false);


//Automatic Dark/Lightmode detection
    connect(QGuiApplication::styleHints(), SIGNAL(colorSchemeChanged (Qt::ColorScheme)), this, SLOT(on_colorSchemeChanged(Qt::ColorScheme)));
    on_colorSchemeChanged(QGuiApplication::styleHints()->colorScheme());

//Automatic accessibilty description updates
    connect(ui->Helligkeit, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Lautstaerke, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Stillstehend_Ton_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Bewegend_Ton_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Stillstehend_Beep_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Bewegend_Beep_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));

//Connect Settings to individual Transmittion
    connect(ui->OnOff_Button, SIGNAL(clicked(bool)), this, SLOT(on_transmitGeneralSettings()));
    connect(ui->Lautstaerke, SIGNAL(valueChanged(int)), this, SLOT(on_transmitSoundFrequenzy()));
    connect(ui->Stillstehend_Ton_Freq, SIGNAL(valueChanged(int)), this, SLOT(on_transmitSoundFrequenzy()));
    connect(ui->Bewegend_Ton_Freq, SIGNAL(valueChanged(int)), this, SLOT(on_transmitSoundFrequenzy()));
    connect(ui->Stillstehend_Beep_Freq, SIGNAL(valueChanged(int)), this, SLOT(on_transmitGeneralSound()));
    connect(ui->Bewegend_Beep_Freq, SIGNAL(valueChanged(int)), this, SLOT(on_transmitGeneralSound()));
    connect(ui->Helligkeit, SIGNAL(valueChanged(int)), this, SLOT(on_transmitGeneralLight()));

    connect(ui->Stillstehend_Farbe1, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe2, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe3, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe4, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe5, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorStill()));

    connect(ui->Bewegend_Farbe1, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe2, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe3, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe4, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe5, SIGNAL(clicked(bool)), SLOT(on_transmitLightColorMoving()));

    ui->uebertragen_button->hide();
    ui->Uebertragen2->hide();
    ui->Uebtragen3->hide();

}

void KlingelballUI::on_colorSchemeChanged(Qt::ColorScheme scheme){
    if(scheme == Qt::ColorScheme::Dark){
        ui->Darkmode_checkBox->setChecked(true);
        ui->Lightmode_checkBox->setChecked(false);
        on_Darkmode_checkBox_clicked();
    }else if (scheme == Qt::ColorScheme::Light){
        ui->Darkmode_checkBox->setChecked(false);
        ui->Lightmode_checkBox->setChecked(true);
        on_Lightmode_checkBox_clicked();
    }
}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}










