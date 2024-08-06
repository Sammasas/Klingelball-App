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
//Translation

    translator = new QTranslator;
    qDebug() << "Opaterating System language" << QLocale::system().name();

    /*if(QLocale::system().name() == "pl_AT"){
        translatorEN->load(":/Translations/Klingelball_App_0_1_pl_PL.qm");
        qApp->installTranslator(translator);
    }*/

    translator->load(":/Translations/Klingelball_App_0_1_pl_PL.qm");
    qApp->installTranslator(translator);



//General Setup

    ui->setupUi(this);
    ui->tabWidget->removeTab(2);
    setup_UI();
    setupBLE();
    setup_Appearance();

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

    connect(ui->Stillstehend_Farbe1, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe2, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe3, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe4, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorStill()));
    connect(ui->Stillstehend_Farbe5, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorStill()));

    connect(ui->Bewegend_Farbe1, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe2, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe3, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe4, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorMoving()));
    connect(ui->Bewegend_Farbe5, SIGNAL(toggled(bool)), SLOT(on_transmitLightColorMoving()));


}



void KlingelballUI::on_colorSchemeChanged(Qt::ColorScheme scheme){
    if(appearance == Appearance::automatically){
        if(scheme == Qt::ColorScheme::Dark){
            qDebug()<< "darkmode";
            setDarkmode();
        }else if (scheme == Qt::ColorScheme::Light){
            qDebug()<< "lightmode";
            setLightmode();
        }
    }
}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}








