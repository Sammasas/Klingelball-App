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
    //TODO add widget on top
}


void KlingelballUI::on_profil_from_currentsettings_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->new_profile_volume_label->setText("Lautstärke" + ui->Volume->text());
    ui->new_profile_Bew_Freq_label->setText("Frequenz-Stillstehend" + ui->Bis_Frequ->text());
    ui->new_profile_Still_Freq_label->setText("Frequenz-Bewegend" + ui->Von_Frequ->text());
}


void KlingelballUI::on_new_profile_button_clicked()
{
    EinstellungsProfil *new_profile = new EinstellungsProfil(ui->new_profile_lineEdit->text(),
                                                             ui->Volume->value(),
                                                             ui->Von_Frequ->value(),
                                                             ui->Bis_Frequ->value());
    createUIProfile(new_profile);
    Profile_list.append(*new_profile);



    ui->new_profile_lineEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}


