#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);
    setup_UI(1.2, 1.5);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);

    ui->Sound_tabWidget->setCurrentIndex(1);
    ui->Sound_tabWidget->setCurrentIndex(0);
    Profile_list = new QList<EinstellungsProfil *>;


    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );

    setupBLE();
    ui->statusLabel->setVisible(false);
    ui->tabWidget->setTabEnabled(2, false);


    connect(QGuiApplication::styleHints(), SIGNAL(colorSchemeChanged (Qt::ColorScheme)), this, SLOT(on_colorSchemeChanged(Qt::ColorScheme)));
    connect(QApplication::instance(), SIGNAL(fontDatabaseChanged()), this, SLOT(on_fontDatabaseChanged()));

}

void  KlingelballUI::on_fontDatabaseChanged(){
    qWarning() <<"font changed!";
    setup_UI();
}

void KlingelballUI::on_colorSchemeChanged(Qt::ColorScheme scheme){
    if(scheme == Qt::ColorScheme::Dark){
        ui->Darkmode_checkBox->click();
    }else if (scheme == Qt::ColorScheme::Light){
        ui->Lightmode_checkBox->click();
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

}


void KlingelballUI::on_Bewegend_Beep_Freq_valueChanged(int arg1)
{

}

