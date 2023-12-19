#include "klingelballui.h"
#include "ui_klingelballui.h"

void KlingelballUI::on_Bis_Frequ_valueChanged(int arg1)
{

}


void KlingelballUI::on_Volume_valueChanged(int arg1)
{
    /*
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(&QTimer::timeout), this, SLOT(playSoundEffect()));
    playSoundEffect(ui->Volume->value());
    timer->start(1000);
    */
}

void KlingelballUI::playSoundEffect(int Volume = 100){

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

void KlingelballUI::create_Profile_visualisation(EinstellungsProfil *profil){

    ui->scrollAreaWidgetContents->layout()->addWidget(profil);
    //TODO add widget on top
}


void KlingelballUI::create_Profile(QString name, int volume, int freq_still, int freq_bew)
{
    EinstellungsProfil *new_profile = new EinstellungsProfil(name, volume, freq_still, freq_bew);

    Profile_list->append(new_profile);
    create_Profile_visualisation(new_profile);

    connect(new_profile, SIGNAL(profile_selected()), this, SLOT(change_profile_selection()));
    connect(new_profile, SIGNAL(profile_selection_updated()), this, SLOT(update_profile_transmittion_state()));
}

void KlingelballUI::destroy_Profile_visualisation(EinstellungsProfil *profil)
{
    ui->scrollAreaWidgetContents->layout()->removeWidget(profil);

}


void KlingelballUI::on_profil_from_currentsettings_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->new_profile_volume_label->setText("Lautstärke: " + ui->Volume->text());
    ui->new_profile_Bew_Freq_label->setText("Frequenz-Stillstehend: " + ui->Bis_Frequ->text());
    ui->new_profile_Still_Freq_label->setText("Frequenz-Bewegend: " + ui->Von_Frequ->text());
}


void KlingelballUI::on_new_profile_button_clicked()
{
    create_Profile(ui->new_profile_lineEdit->text(),
                   ui->Volume->value(),
                   ui->Von_Frequ->value(),
                   ui->Bis_Frequ->value());


    ui->new_profile_lineEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void KlingelballUI::change_profile_selection()
{
    foreach (EinstellungsProfil *profile, *Profile_list) {
        profile->setChecked(false);
    }

}


void KlingelballUI::on_new_profile_cancle_button_clicked()
{
   ui->new_profile_lineEdit->clear();
   ui->stackedWidget->setCurrentIndex(0);
}


void KlingelballUI::on_delete_current_profile_button_clicked()
{
    foreach (EinstellungsProfil *profil, *Profile_list) {
        if(profil->isChecked()){
            destroy_Profile_visualisation(profil);
            Profile_list->removeOne(profil);
            profil->deleteLater();
            update_profile_transmittion_state();
        }
    }

}

void KlingelballUI::set_transmit_profile(bool b)
{
    this->transmit_profile = b;
    if (b == false)
        ui->uebertragen_button->setText("Übertragen");
    else
        ui->uebertragen_button->setText(("Profil übertragen"));
}

void KlingelballUI::update_profile_transmittion_state()
{
    bool b = false;
    foreach (EinstellungsProfil *profil, *Profile_list) {
        if(profil->isChecked())
            b = true;
    }

    if (b)
      set_transmit_profile(true);
    else
      set_transmit_profile(false);
}

void KlingelballUI::on_tabWidget_currentChanged(int index)
{
    QIcon settingsIcon(":/Icons/settings_icon_176440.png");
    QIcon settingsIconInverted(":/Icons/settingsIcon_inverted.png");

    if(index == 3){
        ui->tabWidget->setTabIcon(3, settingsIconInverted);
    }else
        ui->tabWidget->setTabIcon(3, settingsIcon);
}
