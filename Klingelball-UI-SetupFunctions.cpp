    #include "klingelballui.h"
#include "ui_klingelballui.h"


void KlingelballUI::setup_UI(float smallerFontFactor, float fontFactor){

    setup_font(smallerFontFactor, fontFactor);
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
    ui->tabWidget->tabBar()->setAccessibleTabName(0, "Toneinstellungen Tab 1 von 4");
    ui->tabWidget->tabBar()->setAccessibleTabName(1, "Lichteinstellungen Tab 2 von 4");
    ui->tabWidget->tabBar()->setAccessibleTabName(3, "Ball verbinden Tab 3 von 4");
    ui->tabWidget->tabBar()->setAccessibleTabName(4, "Einstellungen Tab 4 von 4");


    ui->Sound_tabWidget->tabBar()->setAccessibleTabName(0, "Tonhöheneinstellung Tab 1 von 2");
    ui->Sound_tabWidget->tabBar()->setAccessibleTabName(1, "Piepseinstellung Tab 2 von 2");


    ui->Lautstaerke->setAccessibleName("Lautstärke" + QString::number(ui->Lautstaerke->value()) + "% Einstellbar");

    ui->verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    ui->tabWidget->setMaximumWidth(qApp->screens()[0]->size().width()+2);

    ui->disconnectKlingelball->setVisible(false);
    ui->OnOff_Button->setVisible(false);
    ui->connectKlingelball->setVisible(false);
    ui->batteryStatusProgressbar->setVisible(false);
    ui->Sound_tabWidget->setAutoFillBackground(true);

    ui->tabWidget->tabBar()->setIconSize(QSize(30, 30));
    ui->Sound_tabWidget->tabBar()->setIconSize(QSize(30, 30));




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

void KlingelballUI::setup_font(float smallerFontFactor, float fontFactor){
    //qWarning() << QString::number(QFontDatabase::systemFont(QFontDatabase::SystemFont::GeneralFont).pointSize());
    //qWarning() << QString::number(QFontDatabase::systemFont(QFontDatabase::SystemFont::FixedFont).pointSize());
    //qWarning() << QString::number(QFontDatabase::systemFont(QFontDatabase::SystemFont::TitleFont).pointSize());



    dynamicSizeFont = new QFont("segue UI", QFontDatabase::systemFont(QFontDatabase::SystemFont::FixedFont).pointSize()*1.5, QFont::Bold);
    SmallerdynamicSizeFont = new QFont("segue UI", QFontDatabase::systemFont(QFontDatabase::SystemFont::FixedFont).pointSize(), QFont::Bold);

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
    ui->Lautstaerke_Label->setFont(*dynamicSizeFont);
    ui->Stillstehend_Ton_Freq_Label->setFont(*dynamicSizeFont);
    ui->Bewegend_Ton_Freq_Label->setFont(*dynamicSizeFont);

    ui->Stillstehend_Beep_Freq_Label->setFont(*dynamicSizeFont);
    ui->Bewegend_Beep_Freq_Label->setFont(*dynamicSizeFont);

    ui->Heilligkeit_Label->setFont(*dynamicSizeFont);
    ui->Stillstehend_Farbe_label->setFont(*SmallerdynamicSizeFont);
    ui->Bewegend_Farbe_Label->setFont(*SmallerdynamicSizeFont);

    ui->Farbe_Label->setFont(*dynamicSizeFont);

    /*ui->new_profile_label->setFont(*dynamicSizeFont);
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

    ui->statusLabel->setTextInteractionFlags(Qt::TextSelectableByMouse );*/
}
