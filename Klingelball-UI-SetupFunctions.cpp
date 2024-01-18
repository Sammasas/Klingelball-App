    #include "klingelballui.h"
#include "ui_klingelballui.h"


void KlingelballUI::setup_UI(){

    setup_font();
    setup_labels();
    setup_buttons();
    setup_spinbox();
    setup_lineedit();
    setup_ButtonGroup();
    ui->tabWidget->setFocusPolicy(Qt::NoFocus);
    ui->Settings_Tab->setFocusPolicy(Qt::NoFocus);
    ui->Profile_Tab->setFocusPolicy(Qt::NoFocus);
    ui->Sound_Tab->setFocusPolicy(Qt::NoFocus);
    ui->centralwidget->setFocusPolicy(Qt::NoFocus);
    ui->tabWidget->tabBar()->setAccessibleTabName(3, "Einstellungen");

    ui->verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    ui->tabWidget->setMaximumWidth(qApp->screens()[0]->size().width()+2);

    ui->disconnectKlingelball->setVisible(false);
    ui->OnOff_Button->setVisible(false);
    ui->connectKlingelball->setVisible(false);
    ui->batteryStatusProgressbar->setVisible(false);

    ui->tabWidget->tabBar()->setStyleSheet("QTabBar{"
                                           "border-top: 2px solid black;}");

    ui->tabWidget->tabBar()->setIconSize(QSize(30, 30));


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

void KlingelballUI::setup_lineedit()
{
    ui->new_profile_lineEdit->setFont(*dynamicSizeFont);
}


void KlingelballUI::setup_spinbox()
{
    ui->Lautstaerke->setFont(*dynamicSizeFont);
    ui->Stillstehend_Ton_Freq->setFont(*dynamicSizeFont);
    ui->Bewegend_Ton_Freq->setFont(*dynamicSizeFont);

    ui->Stillstehend_Beep_Freq->setFont(*dynamicSizeFont);
    ui->Bewegend_Beep_Freq->setFont(*dynamicSizeFont);

    ui->Heilligkeit->setFont(*dynamicSizeFont);
}

void KlingelballUI::setup_font(){
    qreal refDpi = 444.;
    qreal refHeight = 2340.;
    qreal refWidth = 1080.;

    qreal m_ratio = qMin(height/refHeight, width/refWidth);
    qreal m_ratioFont = qMin(height*refDpi/(dpi*refHeight), width*refDpi/(dpi*refWidth));

    QFont serifFont("Times", 16*m_ratioFont, QFont::Bold);


    //testFont = new QFont("segoe UI", ui->Lautstaerke_erhoehen->height()*0.5, QFont::Bold);
}


void KlingelballUI::setup_buttons()
{
    ui->uebertragen_button->setFont(*dynamicSizeFont);
    ui->Uebertragen2->setFont(*dynamicSizeFont);
    ui->Uebtragen3->setFont(*dynamicSizeFont);

    float iconSizeMultiplier = 1.5;

    ui->Lautstaerke_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
    ui->Lautstaerke_verringern->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));

    ui->Bewegend_Ton_Freq_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
    ui->Bewegend_Ton_Freq_verringern->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));

    ui->Stillstehend_Ton_Freq_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
    ui->Stillstehend_Ton_Freq_Verringern->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));

    ui->Stillstehend_Beep_Freq_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
    ui->Stillstehend_Beep_Freq_verringern->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));

    ui->Bewegend_Beep_Freq_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
    ui->Bewegend_Beep_Freq_verringern->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));

    ui->tabWidget->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*0.5, ui->Lautstaerke_erhoehen->height()*0.5));

    ui->new_profile_button->setFont(*dynamicSizeFont);
    ui->new_profile_cancle_button->setFont(*dynamicSizeFont);

    ui->Heilligkeit_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
    ui->Heilligkeit_verringern->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));


}


void KlingelballUI::setup_labels()
{
    dynamicSizeFont = new QFont("segue UI", ui->Lautstaerke_erhoehen->height()*0.6, QFont::Bold);
    SmallerdynamicSizeFont = new QFont("segue UI", ui->Lautstaerke_erhoehen->height()*0.5, QFont::Bold);
    ui->Lautstaerke_Label->setFont(*dynamicSizeFont);
    ui->Stillstehend_Ton_Freq_Label->setFont(*dynamicSizeFont);
    ui->Bewegend_Ton_Freq_Label->setFont(*dynamicSizeFont);

    ui->Stillstehend_Beep_Freq_Label->setFont(*dynamicSizeFont);
    ui->Bewegend_Beep_Freq_Label->setFont(*dynamicSizeFont);

    ui->Heilligkeit_Label->setFont(*dynamicSizeFont);
    ui->Stillstehend_Farbe_label->setFont(*SmallerdynamicSizeFont);
    ui->Bewegend_Farbe_Label->setFont(*SmallerdynamicSizeFont);

    ui->Farbe_Label->setFont(*dynamicSizeFont);

    ui->new_profile_label->setFont(*dynamicSizeFont);
    ui->new_profile_label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->new_profile_volume_label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->new_profile_Bew_Freq_label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->new_profile_Still_Freq_label->setTextInteractionFlags(Qt::TextSelectableByMouse );

    ui->Stillstehend_Beep_Freq_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Bewegend_Beep_Freq_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );



    ui->Lautstaerke_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Stillstehend_Ton_Freq_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Bewegend_Ton_Freq_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Aussehen_label->setTextInteractionFlags(Qt::TextSelectableByMouse);

    ui->statusLabel->setTextInteractionFlags(Qt::TextSelectableByMouse );
}
