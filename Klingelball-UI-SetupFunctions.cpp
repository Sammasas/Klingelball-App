/**********************************************/
//Filename: Klingelball-UI-SetupFunctions.cpp
//Author: Samuel Zeillinger
//Created On: ‎17 ‎Oktober ‎2023 ‏‎13:15
//Description: Functions to setup the UI before runtime
/**********************************************/

#include "klingelballui.h"
#include "ui_klingelballui.h"


void KlingelballUI::setup_UI(){

//Get font scale from Android settings
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

//Get font size and scale from iOS settings
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
    ui->tabWidget->tabBar()->setAccessibleTabName(0, tr("Toneinstellungen Tab 1 von 4"));
    ui->tabWidget->tabBar()->setAccessibleTabName(1, tr("Lichteinstellungen Tab 2 von 4"));
    ui->tabWidget->tabBar()->setAccessibleTabName(2, tr("Ball verbinden Tab 3 von 4"));
    ui->tabWidget->tabBar()->setAccessibleTabName(3, tr("Einstellungen Tab 4 von 4"));




    ui->Sound_tabWidget->tabBar()->setAccessibleTabName(0, tr("Tonhöheneinstellung Tab 1 von 2"));
    ui->Sound_tabWidget->tabBar()->setAccessibleTabName(1, tr("Piepseinstellung Tab 2 von 2"));

    ui->Lautstaerke->setAccessibleName(tr("Lautstärke") + QString::number(ui->Lautstaerke->value()) + tr("% Einstellbar"));

    ui->Stillstehend_Beep_Freq->setAccessibleName(tr("Stillstehende Piepsrequenz")+ QString::number(ui->Stillstehend_Beep_Freq->value()) + tr("% Einstellbar"));
    ui->Bewegend_Beep_Freq->setAccessibleName(tr("Bewegende Piepsrequenz")+ QString::number(ui->Bewegend_Beep_Freq->value()) + tr("% Einstellbar"));

    ui->Stillstehend_Ton_Freq->setAccessibleName(tr("Stillstehende Tonfrequenz")+ QString::number(ui->Stillstehend_Ton_Freq->value()) + tr("% Einstellbar"));
    ui->Stillstehend_Beep_Freq->setAccessibleName(tr("Bewegende Tonfrequenz")+ QString::number(ui->Bewegend_Ton_Freq->value()) + tr("% Einstellbar"));

    ui->Helligkeit->setAccessibleName(tr("Helligkeit") + QString::number(ui->Helligkeit->value())+ tr("% Einstellbar"));


    /***********Setting Content Margins and Size ***/

    ui->centralwidget->setMaximumSize(qApp->screens()[0]->size());

    ui->disconnectKlingelball->setVisible(false);
    ui->OnOff_Button->setVisible(false);
    ui->batteryStatusProgressbar->setVisible(false);
    ui->Sound_tabWidget->setAutoFillBackground(true);
    ui->Sound_tabWidget->setFont(*SmallerdynamicSizeFont);

    ui->tabWidget->tabBar()->setIconSize(QSize(30* *fontScale, 30* *fontScale));
    ui->Sound_tabWidget->tabBar()->setIconSize(QSize(30* *fontScale, 30* *fontScale));

    ui->Erklaerung_textView->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    //Set Values from saved Settings
    connect(stillstehendColorSelectionButtonGroup, SIGNAL(buttonToggled(QAbstractButton*,bool)), this, SLOT(on_buttonGroupToggled(QAbstractButton*,bool)));
    connect(bewegendColorSelectionButtonGroup, SIGNAL(buttonToggled(QAbstractButton*,bool)), this, SLOT(on_buttonGroupToggled(QAbstractButton*,bool)));


    settings = new QSettings("SSA", "Klingelball App");
    if(!settings->contains("Ton/Lautstaerke")){
        ui->Lautstaerke->setValue(50);
        ui->Stillstehend_Ton_Freq->setValue(40);
        ui->Bewegend_Ton_Freq->setValue(40);
        ui->Stillstehend_Beep_Freq->setValue(30);
        ui->Bewegend_Beep_Freq->setValue(30);
        ui->Helligkeit->setValue(100);

        stillstehendColorSelectionButtonGroup->button(4)->setChecked(true);
        stillstehendButtonGroupClicked(stillstehendColorSelectionButtonGroup->button(4));

        bewegendColorSelectionButtonGroup->button(4)->setChecked(true);
        bewegendButtonGroupClicked(bewegendColorSelectionButtonGroup->button(4));

    }else{

        ui->Lautstaerke->setValue(settings->value("Ton/Lautstaerke").toInt());

        ui->Stillstehend_Beep_Freq->setValue(settings->value("Ton/Stillstehend_Beep_Freq").toInt());
        ui->Bewegend_Beep_Freq->setValue(settings->value("Ton/Bewegend_Beep_Freq").toInt());

        ui->Stillstehend_Ton_Freq->setValue(settings->value("Ton/Stillstehend_Ton_Freq").toInt());
        ui->Bewegend_Ton_Freq->setValue(settings->value("Ton/Bewegend_Ton_Freq").toInt());

        ui->Helligkeit->setValue(settings->value("Licht/Helligkeit").toInt());

        if(settings->value("Licht/StillstehendFarbe").toInt() != 0){
            stillstehendColorSelectionButtonGroup->button(settings->value("Licht/StillstehendFarbe").toInt())->setChecked(true);
            stillstehendButtonGroupClicked(stillstehendColorSelectionButtonGroup->button(settings->value("Licht/StillstehendFarbe").toInt()));
        }

        if(settings->value("Licht/BewegendFarbe").toInt() != 0){
            bewegendColorSelectionButtonGroup->button(settings->value("Licht/BewegendFarbe").toInt())->setChecked(true);
            bewegendButtonGroupClicked(bewegendColorSelectionButtonGroup->button(settings->value("Licht/BewegendFarbe").toInt()));
        }
    }

    QScroller::grabGesture(ui->Erklaerung_textView->viewport(), QScroller::LeftMouseButtonGesture);

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

    ui->Helligkeit->setFont(*dynamicSizeFont);
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

    ui->Helligkeit_erhoehen->setIconSize(QSize(ui->Lautstaerke_erhoehen->height()*iconSizeMultiplier, ui->Lautstaerke_erhoehen->height()));
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

    AppearanceButtonGroup = new QButtonGroup;
    AppearanceButtonGroup->addButton(ui->Automatic_checkBox, 1);
    AppearanceButtonGroup->addButton(ui->Darkmode_checkBox, 2);
    AppearanceButtonGroup->addButton(ui->Lightmode_checkBox, 3);


}

void KlingelballUI::setup_Appearance(){
    //Automatic Dark/Lightmode detection
    connect(QGuiApplication::styleHints(), SIGNAL(colorSchemeChanged (Qt::ColorScheme)), this, SLOT(on_colorSchemeChanged(Qt::ColorScheme)));

    if(settings->contains("Appearance")){
        appearance = static_cast<Appearance>(settings->value("Appearance").toInt());
    }else{
        appearance = Appearance::automatically;
    }

    switch(appearance){
    case automatically:
        ui->Automatic_checkBox->setChecked(true);
        on_colorSchemeChanged(QGuiApplication::styleHints()->colorScheme());
        break;
    case lightmode:
        ui->Lightmode_checkBox->setChecked(true);
        setLightmode();
        break;
    case darkmode:
        ui->Darkmode_checkBox->setChecked(true);
        setDarkmode();
        break;
    default:
        ui->Automatic_checkBox->setChecked(true);
        on_colorSchemeChanged(QGuiApplication::styleHints()->colorScheme());
        break;

    }

}
