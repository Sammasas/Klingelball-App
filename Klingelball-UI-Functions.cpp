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

        ui->Bewegend_Farbe1->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor1);
        ui->Bewegend_Farbe2->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor2);
        ui->Bewegend_Farbe3->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor3);
        ui->Bewegend_Farbe4->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor4);
        ui->Bewegend_Farbe5->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor5);

        ui->Stillstehend_Farbe1->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor1);
        ui->Stillstehend_Farbe2->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor2);
        ui->Stillstehend_Farbe3->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor3);
        ui->Stillstehend_Farbe4->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor4);
        ui->Stillstehend_Farbe5->setStyleSheet(RadioButtonCommonStyleLight + RadioButtonColor5);

        setStyleSheet(styleSheet);
        ui->Sound_tabWidget->setStyleSheet("QTabWidget{\n	background-color: red;\n}\n\nQTabWidget::pane {\n  border: 2px solid black;\n  top:-2px; \n  background: solid black;\n	border-radius: 0px;\n} \n\nQTabBar{\n	border-top: 0px;\n}\n\nQTabBar::tab {\n  background: rgb(230, 230, 230); \n  \n	padding: 15px;\n	margin-left: 0px;\n	margin-right: 0px;\n\n  \n} \n\nQTabBar::tab:unselected{\n	background: darkgrey;\n   top: 5px; \n	\n	border-radius: 0px;\n	border-bottom: 2px  solid black;\n	border-top: 1px solid lightgrey;\n	border-left: 1px solid lightgrey;\n	border-right: 1px solid lightgrey;\n	\n}\n\nQTabBar::tab:selected { \nborder: 2px solid black; \n  background: transparent; \n  margin-bottom: -2px; \nborder-bottom: 2px solid #e50616;\n}\n\nQTabBar::tab::disabled{\n    width: 0;\n    height: 0;\n    margin: 0;\n    padding: 0;\n    border: none;\n}");
        ui->tabWidget->setStyleSheet("\n\nQTabBar::tab{\n    margin-left: 10px;\n    margin-right: 10px;\n    margin-bottom: 5px;\n    margin-top: 10px;\n\n    /*padding-left: 5px;\n    padding-right: 5px;*/\n\n}\n\nQTabWidget::tab-bar {\n    alignment: center;\n	\n\n}\n\nQTabBar{\nborder-top: 2px solid black;\n    alignment: center;\n\n}\n\nQTabBar::tab:selected {\n    color: #e50616;\n    background: transparent;\n    border-bottom: 2px solid #e50616;\n\n}\n\nQTabBar::tab:!selected {\n    color: black;\n    background: transparent;\n    \n}\n\nQTabBar::tab::disabled{\n    width: 0;\n    height: 0;\n    margin: 0;\n    padding: 0;\n    border: none;\n}");

        ui->line->setStyleSheet("color: black;");
        ui->line_2->setStyleSheet("color: black;");
        ui->line_3->setStyleSheet("color: black;");

        ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_dark.png"));
        ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_light.png"));
        ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon.png"));
        ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_176440.png"));

        on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
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

        ui->Bewegend_Farbe1->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor1);
        ui->Bewegend_Farbe2->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor2);
        ui->Bewegend_Farbe3->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor3);
        ui->Bewegend_Farbe4->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor4);
        ui->Bewegend_Farbe5->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor5);

        ui->Stillstehend_Farbe1->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor1);
        ui->Stillstehend_Farbe2->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor2);
        ui->Stillstehend_Farbe3->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor3);
        ui->Stillstehend_Farbe4->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor4);
        ui->Stillstehend_Farbe5->setStyleSheet(RadioButtonCommonStyleDark + RadioButtonColor5);

        setStyleSheet(styleSheet);
        ui->Sound_tabWidget->setStyleSheet("QTabWidget{\n	background-color: red;\n}\n\nQTabWidget::pane {\n  border: 2px solid white;\n  top:-2px; \n  background: solid white;\n	border-radius: 0px;\n} \n\nQTabBar{\n	border-top: 0px;\n}\n\nQTabBar::tab {\n  background: rgb(230, 230, 230); \n  \n	padding: 15px;\n	margin-left: 0px;\n	margin-right: 0px;\n\n  \n} \n\nQTabBar::tab:unselected{\n	background: darkgrey;\n   top: 5px; \n	\n	border-radius: 0px;\n	border-bottom: 2px  solid black;\n	border-top: 1px solid lightgrey;\n	border-left: 1px solid lightgrey;\n	border-right: 1px solid lightgrey;\n	\n}\n\nQTabBar::tab:selected { \nborder: 2px solid white; \n  background: transparent; \n  margin-bottom: -2px; \nborder-bottom: 2px solid #e50616;\n}\n\nQTabBar::tab::disabled{\n    width: 0;\n    height: 0;\n    margin: 0;\n    padding: 0;\n    border: none;\n}");
        ui->tabWidget->setStyleSheet("\n\nQTabBar::tab{\n    margin-left: 10px;\n    margin-right: 10px;\n    margin-bottom: 5px;\n    margin-top: 10px;\n\n    /*padding-left: 5px;\n    padding-right: 5px;*/\n\n}\n\nQTabWidget::tab-bar {\n    alignment: center;\n	\n\n}\n\nQTabBar{\nborder-top: 2px solid white;\n    alignment: center;\n\n}\n\nQTabBar::tab:selected {\n    color: #e50616;\n    background: transparent;\n    border-bottom: 2px solid #e50616;\n\n}\n\nQTabBar::tab:!selected {\n    color: black;\n    background: transparent;\n    \n}\n\nQTabBar::tab::disabled{\n    width: 0;\n    height: 0;\n    margin: 0;\n    padding: 0;\n    border: none;\n}");

        ui->line->setStyleSheet("color: white;");
        ui->line_2->setStyleSheet("color: white;");
        ui->line_3->setStyleSheet("color: white;");

        ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_light.png"));
        ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_dark.png"));
        ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon_inverted.png"));
        ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settingsIcon_inverted.png"));

        on_tabWidget_currentChanged(ui->tabWidget->currentIndex());
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
    ui->new_profile_volume_label->setText("Lautstärke: " + ui->Lautstaerke->text());
    ui->new_profile_Bew_Freq_label->setText("Frequenz-Stillstehend: " + ui->Stillstehend_Ton_Freq->text());
    ui->new_profile_Still_Freq_label->setText("Frequenz-Bewegend: " + ui->Bewegend_Ton_Freq->text());
}


void KlingelballUI::on_new_profile_button_clicked()
{
    create_Profile(ui->new_profile_lineEdit->text(),
                   ui->Lautstaerke->value(),
                   ui->Stillstehend_Ton_Freq->value(),
                   ui->Bewegend_Ton_Freq->value());


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

    if(ui->Darkmode_checkBox->isChecked()){
        switch(index){
        case 0:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_red.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_dark.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon_inverted.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settingsIcon_inverted.png"));
            break;
        case 1:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_light.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light-icon_red.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon_inverted.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settingsIcon_inverted.png"));
            break;
        case 3:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_light.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_dark.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/ball_icon_red.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settingsIcon_inverted.png"));
            break;
        case 4:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_light.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_dark.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon_inverted.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_red.png"));
            break;
        default:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_light.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_dark.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon_inverted.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_red.png"));
            break;
        }
    }else if (ui->Lightmode_checkBox->isChecked()){
        switch(index){
        case 0:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_red.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_light.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_176440.png"));
            break;
        case 1:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_dark.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light-icon_red.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_176440.png"));
            break;
        case 3:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_dark.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_light.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/ball_icon_red.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_176440.png"));
            break;
        case 4:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_dark.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_light.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_red.png"));
            break;
        default:
            ui->tabWidget->setTabIcon(0, QIcon(":/Icons/lautstarke_dark.png"));
            ui->tabWidget->setTabIcon(1, QIcon(":/Icons/light_icon_light.png"));
            ui->tabWidget->setTabIcon(3, QIcon(":/Icons/Ball_icon.png"));
            ui->tabWidget->setTabIcon(4, QIcon(":/Icons/settings_icon_176440.png"));
            break;
        }
    }





}

void KlingelballUI::on_OnOff_Button_toggled(bool checked)
{
    if(checked){
        ui->OnOff_Button->setText("Ball: Ein");
    }else{
        ui->OnOff_Button->setText("Ball: Aus");
    }
}

void KlingelballUI::on_UIDeviceList_currentRowChanged(int currentRow)
{
    if(!ui->connectKlingelball->isVisible()){
        ui->connectKlingelball->setVisible(true);
    }
    if(currentRow == -1){
        ui->connectKlingelball->setVisible(false);
    }
}

void KlingelballUI::setup_ButtonGroup(){
    stillstehendColorSelectionButtonGroup = new QButtonGroup;
    stillstehendColorSelectionButtonGroup->addButton(ui->Stillstehend_Farbe1, 1);
    stillstehendColorSelectionButtonGroup->addButton(ui->Stillstehend_Farbe2, 2);
    stillstehendColorSelectionButtonGroup->addButton(ui->Stillstehend_Farbe3, 3);
    stillstehendColorSelectionButtonGroup->addButton(ui->Stillstehend_Farbe4, 4);
    stillstehendColorSelectionButtonGroup->addButton(ui->Stillstehend_Farbe5, 5);


    bewegendColorSelectionButtonGroup = new QButtonGroup;
    bewegendColorSelectionButtonGroup->addButton(ui->Bewegend_Farbe1, 1);
    bewegendColorSelectionButtonGroup->addButton(ui->Bewegend_Farbe2, 2);
    bewegendColorSelectionButtonGroup->addButton(ui->Bewegend_Farbe3, 3);
    bewegendColorSelectionButtonGroup->addButton(ui->Bewegend_Farbe4, 4);
    bewegendColorSelectionButtonGroup->addButton(ui->Bewegend_Farbe5, 5);

    connect(stillstehendColorSelectionButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(stillstehendButtonGroupClicked(QAbstractButton*)));
    connect(bewegendColorSelectionButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(bewegendButtonGroupClicked(QAbstractButton*)));
}

void KlingelballUI::stillstehendButtonGroupClicked(QAbstractButton *button){
    if(stillstehendButtonGroupOneSelected){
        if(button->isChecked() && (stillstehendColorSelectionButtonGroup->id(button) == stillstehendButtonGroupSelectedID)){
            stillstehendColorSelectionButtonGroup->setExclusive(false);
            button->setChecked(false);
            stillstehendColorSelectionButtonGroup->setExclusive(true);
            stillstehendButtonGroupOneSelected = false;
            stillstehendButtonGroupSelectedID = 0;
        }else{
            stillstehendButtonGroupSelectedID = stillstehendColorSelectionButtonGroup->id(button);
        }
    }else{
        stillstehendButtonGroupOneSelected = true;
        stillstehendButtonGroupSelectedID = stillstehendColorSelectionButtonGroup->id(button);
    }

}

void KlingelballUI::bewegendButtonGroupClicked(QAbstractButton *button){
    if(bewegendButtonGroupOneSelected){
        if(button->isChecked() && (bewegendColorSelectionButtonGroup->id(button) == bewegendButtonGroupSelectedID)){
            bewegendColorSelectionButtonGroup->setExclusive(false);
            button->setChecked(false);
            bewegendColorSelectionButtonGroup->setExclusive(true);
            bewegendButtonGroupOneSelected = false;
            bewegendButtonGroupSelectedID = 0;
        }else{
            bewegendButtonGroupSelectedID = bewegendColorSelectionButtonGroup->id(button);
        }
    }else{
        bewegendButtonGroupOneSelected = true;
        bewegendButtonGroupSelectedID = bewegendColorSelectionButtonGroup->id(button);
    }
}

