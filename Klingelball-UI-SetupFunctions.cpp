    #include "klingelballui.h"
#include "ui_klingelballui.h"


void KlingelballUI::setup_UI(){


#ifdef Q_OS_ANDROID
    QJniObject context = QNativeInterface::QAndroidApplication::context();
    if(QJniObject::isClassAvailable("Klingelball/AndroidSettings")) {
        QJniObject androidSettingsJavaObject = QJniObject("Klingelball/AndroidSettings");

        fontScale = new float(androidSettingsJavaObject.callStaticMethod<jfloat>("Klingelball/AndroidSettings", "getFontScale", "(Landroid/content/Context;)F", context.object<jobject>()));
        qDebug() <<"Font scale:" << *fontScale;
        setup_fontAndroid(*fontScale);

    }
    else {
        qDebug() << "JAVA CLASS UNAVAIABLE!";
        fontScale = new float(1);
        setup_fontAndroid(*fontScale);

    }
#endif

#ifdef Q_OS_IOS
        qDebug() << "iOS Font:" << iOSSettings::getPrefferedFont();
        qDebug() << "Qt Font:" << QFontDatabase::systemFont(QFontDatabase::SystemFont::FixedFont).pointSize();
        fontScale = new float(getfontScalefrompointSize(iOSSettings::getPrefferedFont()));
        setup_fontiOS(iOSSettings::getPrefferedFont());
#endif

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


    /*********Setting accessible names **********/
    ui->tabWidget->tabBar()->setAccessibleTabName(0, "Toneinstellungen Tab 1 von 4");
    ui->tabWidget->tabBar()->setAccessibleTabName(1, "Lichteinstellungen Tab 2 von 4");
    ui->tabWidget->tabBar()->setAccessibleTabName(2, "Ball verbinden Tab 3 von 4");
    ui->tabWidget->tabBar()->setAccessibleTabName(3, "Einstellungen Tab 4 von 4");


    ui->Sound_tabWidget->tabBar()->setAccessibleTabName(0, "Tonhöheneinstellung Tab 1 von 2");
    ui->Sound_tabWidget->tabBar()->setAccessibleTabName(1, "Piepseinstellung Tab 2 von 2");

    ui->Lautstaerke->setAccessibleName("Lautstärke" + QString::number(ui->Lautstaerke->value()) + "% Einstellbar");

    ui->Stillstehend_Beep_Freq->setAccessibleName("Stillstehende Piepsrequenz"+ QString::number(ui->Stillstehend_Beep_Freq->value()) + "% Einstellbar");
    ui->Bewegend_Beep_Freq->setAccessibleName("Bewegende Piepsrequenz"+ QString::number(ui->Bewegend_Beep_Freq->value()) + "% Einstellbar");

    ui->Stillstehend_Ton_Freq->setAccessibleName("Stillstehende Tonfrequenz"+ QString::number(ui->Stillstehend_Ton_Freq->value()) + "% Einstellbar");
    ui->Stillstehend_Beep_Freq->setAccessibleName("Bewegende Tonfrequenz"+ QString::number(ui->Bewegend_Ton_Freq->value()) + "% Einstellbar");

    ui->Heilligkeit->setAccessibleName("Helligkeit" + QString::number(ui->Heilligkeit->value())+ "% Einstellbar");


    /***********Setting Content Margins and Size ***/

    ui->centralwidget->setMaximumSize(qApp->screens()[0]->size());
    //ui->Sound_tabWidget->setFixedHeight( ui->Sound_tabWidget->height()+6);

    ui->disconnectKlingelball->setVisible(false);
    ui->OnOff_Button->setVisible(false);
    ui->connectKlingelball->setVisible(false);
    ui->batteryStatusProgressbar->setVisible(false);
    ui->ErrormessageLabel->setVisible(false);
    ui->ErrormessageLabelSecline->setVisible(false);
    ui->Sound_tabWidget->setAutoFillBackground(true);

    ui->Sound_tabWidget->setFont(*SmallerdynamicSizeFont);

    ui->tabWidget->tabBar()->setIconSize(QSize(30* *fontScale, 30* *fontScale));
    ui->Sound_tabWidget->tabBar()->setIconSize(QSize(30* *fontScale, 30* *fontScale));

}

float KlingelballUI::getfontScalefrompointSize(int pointSize){
    switch(pointSize){
    case 14:
        return 0.8;
    case 15:
        return 0.85;
    case 16:
        return 0.9;
    case 17:
        return 1;
    case 19:
        return 1.1;
    case 21:
        return 1.2;
    case 23:
        return 1.3;
    default:
        return 1;
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

void KlingelballUI::setup_fontAndroid(float fontScale){
    dynamicSizeFont = new QFont("segue UI", QFontDatabase::systemFont(QFontDatabase::SystemFont::FixedFont).pointSize()*fontScale*1.3, QFont::Bold);
    SmallerdynamicSizeFont = new QFont("segue UI", QFontDatabase::systemFont(QFontDatabase::SystemFont::FixedFont).pointSize()*fontScale, QFont::Bold);
}

void KlingelballUI::setup_fontiOS(int pointSize){
    dynamicSizeFont = new QFont("segue UI", pointSize*1.3, QFont::Bold);
    SmallerdynamicSizeFont = new QFont("segue UI", pointSize, QFont::Bold);
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
    ui->Stillstehend_Ton_Freq_Label->setFont(*SmallerdynamicSizeFont);
    ui->Bewegend_Ton_Freq_Label->setFont(*SmallerdynamicSizeFont);

    ui->Stillstehend_Beep_Freq_Label->setFont(*SmallerdynamicSizeFont);
    ui->Bewegend_Beep_Freq_Label->setFont(*SmallerdynamicSizeFont);

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
