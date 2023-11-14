#include "klingelballui.h"
#include "ui_klingelballui.h"

void KlingelballUI::on_Bis_Frequ_valueChanged(int arg1)
{

}


void KlingelballUI::on_Volume_valueChanged(int arg1)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(&QTimer::timeout), this, SLOT(playSoundEffect(arg1)));
    playSoundEffect(ui->Volume->value());
    timer->start(1000);
}

void KlingelballUI::playSoundEffect(int Volume){
    effect.setSource(QUrl::fromLocalFile(":/SoundFiles/beepV1.wav"));
    effect.setLoopCount(1);
    effect.setVolume((float)Volume/100);
    effect.play();
}




void KlingelballUI::on_Lightmode_checkBox_clicked()
{
    if(ui->Lightmode_checkBox->isChecked()){
        ui->Lightmode_checkBox->setDisabled(true);
        ui->Darkmode_checkBox->setDisabled(false);
        ui->Darkmode_checkBox->setCheckState(Qt::Unchecked);

        QFile styleSheetFile(":/stylesheet/lightmode.css");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        setStyleSheet(styleSheet);
    }
}


void KlingelballUI::on_Darkmode_checkBox_clicked()
{
    if(ui->Darkmode_checkBox->isChecked()){
        ui->Darkmode_checkBox->setDisabled(true);
        ui->Lightmode_checkBox->setDisabled(false);
        ui->Lightmode_checkBox->setCheckState(Qt::Unchecked);

        QFile styleSheetFile(":/stylesheet/darkmode.css");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        setStyleSheet(styleSheet);
    }
}

void KlingelballUI::createUIProfile(EinstellungsProfil *profil){

    ui->scrollAreaWidgetContents->layout()->addWidget(profil);
}
