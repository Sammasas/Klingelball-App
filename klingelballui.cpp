#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(2);
    setup_UI();
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);

    ui->Sound_tabWidget->setCurrentIndex(0);


    Profile_list = new QList<EinstellungsProfil *>;


    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );

    setupBLE();
    ui->statusLabel->setVisible(false);
    //ui->tabWidget->setTabEnabled(2, false);


    connect(QGuiApplication::styleHints(), SIGNAL(colorSchemeChanged (Qt::ColorScheme)), this, SLOT(on_colorSchemeChanged(Qt::ColorScheme)));
    on_colorSchemeChanged(QGuiApplication::styleHints()->colorScheme());

    connect(ui->Heilligkeit, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Lautstaerke, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Stillstehend_Ton_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Bewegend_Ton_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Stillstehend_Beep_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));
    connect(ui->Bewegend_Beep_Freq, SIGNAL(valueChanged(int)), this, SLOT(updateAccessibleDesciption()));

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





void KlingelballUI::on_Lautstaerke_valueChanged(int arg1)
{
    ui->Lautstaerke->setAccessibleName("Lautstärke" + QString::number(arg1) + "% Einstellbar");
}


void KlingelballUI::on_Stillstehend_Beep_Freq_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
}


void KlingelballUI::on_Bewegend_Beep_Freq_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
}

