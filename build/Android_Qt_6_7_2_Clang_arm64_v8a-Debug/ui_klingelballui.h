/********************************************************************************
** Form generated from reading UI file 'klingelballui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KLINGELBALLUI_H
#define UI_KLINGELBALLUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KlingelballUI
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *Sound_Tab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *Volume_Layout;
    QLabel *Lautstaerke_Label;
    QPushButton *Lautstaerke_erhoehen;
    QSpinBox *Lautstaerke;
    QPushButton *Lautstaerke_verringern;
    QFrame *line;
    QTabWidget *Sound_tabWidget;
    QWidget *Ton_tab;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *Ton_Layout;
    QLabel *Stillstehend_Ton_Freq_Label;
    QFrame *line_3;
    QPushButton *Stillstehend_Ton_Freq_erhoehen;
    QSpinBox *Stillstehend_Ton_Freq;
    QPushButton *Stillstehend_Ton_Freq_Verringern;
    QLabel *Bewegend_Ton_Freq_Label;
    QPushButton *Bewegend_Ton_Freq_erhoehen;
    QSpinBox *Bewegend_Ton_Freq;
    QPushButton *Bewegend_Ton_Freq_verringern;
    QWidget *Beep_tab;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *Beep_Layout;
    QPushButton *Bewegend_Beep_Freq_verringern;
    QLabel *Bewegend_Beep_Freq_Label;
    QPushButton *Bewegend_Beep_Freq_erhoehen;
    QPushButton *Stillstehend_Beep_Freq_erhoehen;
    QLabel *Stillstehend_Beep_Freq_Label;
    QSpinBox *Bewegend_Beep_Freq;
    QSpinBox *Stillstehend_Beep_Freq;
    QPushButton *Stillstehend_Beep_Freq_verringern;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pause_button;
    QWidget *Light_Tab;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *Helligkeit_Layout;
    QLabel *Heilligkeit_Label;
    QPushButton *Helligkeit_erhoehen;
    QSpinBox *Helligkeit;
    QPushButton *Heilligkeit_verringern;
    QLabel *Farbe_Label;
    QGroupBox *StillstehendColorSelectionGroupBox;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout_6;
    QRadioButton *Stillstehend_Farbe1;
    QRadioButton *Stillstehend_Farbe2;
    QRadioButton *Stillstehend_Farbe4;
    QRadioButton *Stillstehend_Farbe3;
    QRadioButton *Stillstehend_Farbe5;
    QLabel *Stillstehend_Farbe_label;
    QGroupBox *BewegendColorSelectionGroupBox;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *gridLayout_3;
    QLabel *Bewegend_Farbe_Label;
    QRadioButton *Bewegend_Farbe1;
    QRadioButton *Bewegend_Farbe2;
    QRadioButton *Bewegend_Farbe4;
    QRadioButton *Bewegend_Farbe3;
    QRadioButton *Bewegend_Farbe5;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pause_button2;
    QWidget *Profile_Tab;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *Profil_page;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QPushButton *profil_from_currentsettings_button;
    QPushButton *delete_current_profile_button;
    QWidget *new_profile_page;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QLabel *new_profile_label;
    QLineEdit *new_profile_lineEdit;
    QPushButton *new_profile_button;
    QLabel *new_profile_volume_label;
    QLabel *new_profile_Bew_Freq_label;
    QLabel *new_profile_Still_Freq_label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *new_profile_cancle_button;
    QWidget *edit_profile_page;
    QWidget *Ball_Tab;
    QVBoxLayout *verticalLayout_6;
    QListWidget *UIDeviceList;
    QLabel *label;
    QPushButton *searchKlingelball;
    QPushButton *disconnectKlingelball;
    QPushButton *OnOff_Button;
    QProgressBar *batteryStatusProgressbar;
    QSpacerItem *verticalSpacer;
    QWidget *Settings_Tab;
    QVBoxLayout *verticalLayout_10;
    QLabel *Aussehen_label;
    QCheckBox *Automatic_checkBox;
    QCheckBox *Lightmode_checkBox;
    QCheckBox *Darkmode_checkBox;
    QTextBrowser *Erklaerung_textView;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QMainWindow *KlingelballUI)
    {
        if (KlingelballUI->objectName().isEmpty())
            KlingelballUI->setObjectName("KlingelballUI");
        KlingelballUI->resize(462, 785);
        KlingelballUI->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/ButtonUp.png);}"));
        centralwidget = new QWidget(KlingelballUI);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(27);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        tabWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QTabBar::tab{\n"
"    margin-left: 10px;\n"
"    margin-right: 10px;\n"
"    margin-bottom: 5px;\n"
"    margin-top: 10px;\n"
"\n"
"padding-right: -10px;\n"
"	padding-left: 4px;\n"
"\n"
"    /*padding-left: 5px;\n"
"    padding-right: 5px;*/\n"
"\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"	\n"
"\n"
"}\n"
"\n"
"QTabBar{\n"
"border-top: 2px solid black;\n"
"    alignment: center;\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #e50616;\n"
"    background: transparent;\n"
"    border-bottom: 2px solid #e50616;\n"
"	padding-right: -10px;\n"
"	padding-left: 4px;\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"	color: black;\n"
"	background: transparent;\n"
"	padding-right: -10px;\n"
"	padding-left: 4px;\n"
"    \n"
"}\n"
"\n"
"QTabBar::tab::disabled{\n"
"    width: 0;\n"
"    height: 0;\n"
"    margin: 0;\n"
"    padding: 0;\n"
"    border: none;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::TabPosition::South);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setIconSize(QSize(30, 30));
        tabWidget->setElideMode(Qt::TextElideMode::ElideLeft);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        Sound_Tab = new QWidget();
        Sound_Tab->setObjectName("Sound_Tab");
        verticalLayout_3 = new QVBoxLayout(Sound_Tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(10, -1, 10, -1);
        Volume_Layout = new QVBoxLayout();
        Volume_Layout->setSpacing(4);
        Volume_Layout->setObjectName("Volume_Layout");
        Volume_Layout->setContentsMargins(-1, -1, -1, 5);
        Lautstaerke_Label = new QLabel(Sound_Tab);
        Lautstaerke_Label->setObjectName("Lautstaerke_Label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Lautstaerke_Label->sizePolicy().hasHeightForWidth());
        Lautstaerke_Label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Magneto")});
        font1.setPointSize(20);
        font1.setBold(false);
        Lautstaerke_Label->setFont(font1);
        Lautstaerke_Label->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        Volume_Layout->addWidget(Lautstaerke_Label);

        Lautstaerke_erhoehen = new QPushButton(Sound_Tab);
        Lautstaerke_erhoehen->setObjectName("Lautstaerke_erhoehen");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Lautstaerke_erhoehen->sizePolicy().hasHeightForWidth());
        Lautstaerke_erhoehen->setSizePolicy(sizePolicy2);
        Lautstaerke_erhoehen->setMinimumSize(QSize(0, 40));
        Lautstaerke_erhoehen->setMaximumSize(QSize(16777215, 60));
        Lautstaerke_erhoehen->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Lautstaerke_erhoehen->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        Lautstaerke_erhoehen->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Chevron_Up_inverted.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Lautstaerke_erhoehen->setIcon(icon);
        Lautstaerke_erhoehen->setIconSize(QSize(40, 12));
        Lautstaerke_erhoehen->setAutoDefault(false);
        Lautstaerke_erhoehen->setFlat(false);

        Volume_Layout->addWidget(Lautstaerke_erhoehen);

        Lautstaerke = new QSpinBox(Sound_Tab);
        Lautstaerke->setObjectName("Lautstaerke");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Lautstaerke->sizePolicy().hasHeightForWidth());
        Lautstaerke->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        Lautstaerke->setFont(font2);
        Lautstaerke->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        Lautstaerke->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Lautstaerke->setFrame(false);
        Lautstaerke->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Lautstaerke->setReadOnly(false);
        Lautstaerke->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        Lautstaerke->setKeyboardTracking(false);
        Lautstaerke->setMaximum(100);
        Lautstaerke->setSingleStep(5);

        Volume_Layout->addWidget(Lautstaerke);

        Lautstaerke_verringern = new QPushButton(Sound_Tab);
        Lautstaerke_verringern->setObjectName("Lautstaerke_verringern");
        sizePolicy2.setHeightForWidth(Lautstaerke_verringern->sizePolicy().hasHeightForWidth());
        Lautstaerke_verringern->setSizePolicy(sizePolicy2);
        Lautstaerke_verringern->setMinimumSize(QSize(0, 40));
        Lautstaerke_verringern->setMaximumSize(QSize(16777215, 60));
        Lautstaerke_verringern->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Chevron_down_inverted.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Lautstaerke_verringern->setIcon(icon1);

        Volume_Layout->addWidget(Lautstaerke_verringern);

        Volume_Layout->setStretch(0, 4);
        Volume_Layout->setStretch(1, 4);
        Volume_Layout->setStretch(2, 4);
        Volume_Layout->setStretch(3, 4);

        verticalLayout_3->addLayout(Volume_Layout);

        line = new QFrame(Sound_Tab);
        line->setObjectName("line");
        line->setAutoFillBackground(false);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line);

        Sound_tabWidget = new QTabWidget(Sound_Tab);
        Sound_tabWidget->setObjectName("Sound_tabWidget");
        sizePolicy2.setHeightForWidth(Sound_tabWidget->sizePolicy().hasHeightForWidth());
        Sound_tabWidget->setSizePolicy(sizePolicy2);
        Sound_tabWidget->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        Sound_tabWidget->setFont(font3);
        Sound_tabWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Sound_tabWidget->setAutoFillBackground(false);
        Sound_tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{\n"
"	background-color: red;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"  border: 2px solid black;\n"
"  top:-2px; \n"
"  background: solid black;\n"
"	border-radius: 0px;\n"
"} \n"
"\n"
"QTabBar{\n"
"	border-top: 0px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"  background: rgb(230, 230, 230); \n"
"  \n"
"	padding: 15px;\n"
"	margin-left: 0px;\n"
"	margin-right: 0px;\n"
"\n"
"  \n"
"} \n"
"\n"
"QTabBar::tab:unselected{\n"
"	background: darkgrey;\n"
"    top: 5px; \n"
"	\n"
"	border-radius: 0px;\n"
"	border-bottom: 2px  solid black;\n"
"	border-top: 1px solid lightgrey;\n"
"	border-left: 1px solid lightgrey;\n"
"	border-right: 1px solid lightgrey;\n"
"	\n"
"}\n"
"\n"
"QTabBar::tab:selected { \n"
"border: 2px solid black; \n"
"  background: transparent; \n"
"  margin-bottom: -2px; \n"
"border-bottom: 2px solid #e50616;\n"
"}\n"
"\n"
"QTabBar::tab::disabled{\n"
"    width: 0;\n"
"    height: 0;\n"
"    margin: 0;\n"
"    padding: 0;\n"
"    border: none;\n"
"}"));
        Sound_tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        Sound_tabWidget->setElideMode(Qt::TextElideMode::ElideLeft);
        Sound_tabWidget->setTabsClosable(false);
        Sound_tabWidget->setTabBarAutoHide(false);
        Ton_tab = new QWidget();
        Ton_tab->setObjectName("Ton_tab");
        QPalette palette;
        Ton_tab->setPalette(palette);
        Ton_tab->setAutoFillBackground(true);
        Ton_tab->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(Ton_tab);
        verticalLayout_5->setObjectName("verticalLayout_5");
        Ton_Layout = new QGridLayout();
        Ton_Layout->setObjectName("Ton_Layout");
        Ton_Layout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        Ton_Layout->setHorizontalSpacing(20);
        Ton_Layout->setVerticalSpacing(4);
        Stillstehend_Ton_Freq_Label = new QLabel(Ton_tab);
        Stillstehend_Ton_Freq_Label->setObjectName("Stillstehend_Ton_Freq_Label");
        Stillstehend_Ton_Freq_Label->setFont(font2);
        Stillstehend_Ton_Freq_Label->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Stillstehend_Ton_Freq_Label->setStyleSheet(QString::fromUtf8(""));

        Ton_Layout->addWidget(Stillstehend_Ton_Freq_Label, 1, 0, 1, 1);

        line_3 = new QFrame(Ton_tab);
        line_3->setObjectName("line_3");
        line_3->setLineWidth(2);
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        Ton_Layout->addWidget(line_3, 2, 1, 3, 1);

        Stillstehend_Ton_Freq_erhoehen = new QPushButton(Ton_tab);
        Stillstehend_Ton_Freq_erhoehen->setObjectName("Stillstehend_Ton_Freq_erhoehen");
        sizePolicy2.setHeightForWidth(Stillstehend_Ton_Freq_erhoehen->sizePolicy().hasHeightForWidth());
        Stillstehend_Ton_Freq_erhoehen->setSizePolicy(sizePolicy2);
        Stillstehend_Ton_Freq_erhoehen->setMinimumSize(QSize(0, 40));
        Stillstehend_Ton_Freq_erhoehen->setMaximumSize(QSize(16777215, 60));
        Stillstehend_Ton_Freq_erhoehen->setIcon(icon);

        Ton_Layout->addWidget(Stillstehend_Ton_Freq_erhoehen, 2, 0, 1, 1);

        Stillstehend_Ton_Freq = new QSpinBox(Ton_tab);
        Stillstehend_Ton_Freq->setObjectName("Stillstehend_Ton_Freq");
        sizePolicy.setHeightForWidth(Stillstehend_Ton_Freq->sizePolicy().hasHeightForWidth());
        Stillstehend_Ton_Freq->setSizePolicy(sizePolicy);
        Stillstehend_Ton_Freq->setFont(font2);
        Stillstehend_Ton_Freq->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        Stillstehend_Ton_Freq->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Stillstehend_Ton_Freq->setWrapping(false);
        Stillstehend_Ton_Freq->setFrame(false);
        Stillstehend_Ton_Freq->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Stillstehend_Ton_Freq->setReadOnly(false);
        Stillstehend_Ton_Freq->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        Stillstehend_Ton_Freq->setKeyboardTracking(false);
        Stillstehend_Ton_Freq->setMaximum(100);
        Stillstehend_Ton_Freq->setSingleStep(5);

        Ton_Layout->addWidget(Stillstehend_Ton_Freq, 3, 0, 1, 1);

        Stillstehend_Ton_Freq_Verringern = new QPushButton(Ton_tab);
        Stillstehend_Ton_Freq_Verringern->setObjectName("Stillstehend_Ton_Freq_Verringern");
        sizePolicy2.setHeightForWidth(Stillstehend_Ton_Freq_Verringern->sizePolicy().hasHeightForWidth());
        Stillstehend_Ton_Freq_Verringern->setSizePolicy(sizePolicy2);
        Stillstehend_Ton_Freq_Verringern->setMinimumSize(QSize(0, 40));
        Stillstehend_Ton_Freq_Verringern->setMaximumSize(QSize(16777215, 60));
        Stillstehend_Ton_Freq_Verringern->setIcon(icon1);

        Ton_Layout->addWidget(Stillstehend_Ton_Freq_Verringern, 4, 0, 1, 1);

        Bewegend_Ton_Freq_Label = new QLabel(Ton_tab);
        Bewegend_Ton_Freq_Label->setObjectName("Bewegend_Ton_Freq_Label");
        sizePolicy.setHeightForWidth(Bewegend_Ton_Freq_Label->sizePolicy().hasHeightForWidth());
        Bewegend_Ton_Freq_Label->setSizePolicy(sizePolicy);
        Bewegend_Ton_Freq_Label->setFont(font2);

        Ton_Layout->addWidget(Bewegend_Ton_Freq_Label, 1, 2, 1, 1);

        Bewegend_Ton_Freq_erhoehen = new QPushButton(Ton_tab);
        Bewegend_Ton_Freq_erhoehen->setObjectName("Bewegend_Ton_Freq_erhoehen");
        sizePolicy2.setHeightForWidth(Bewegend_Ton_Freq_erhoehen->sizePolicy().hasHeightForWidth());
        Bewegend_Ton_Freq_erhoehen->setSizePolicy(sizePolicy2);
        Bewegend_Ton_Freq_erhoehen->setMinimumSize(QSize(0, 40));
        Bewegend_Ton_Freq_erhoehen->setMaximumSize(QSize(16777215, 60));
        Bewegend_Ton_Freq_erhoehen->setIcon(icon);

        Ton_Layout->addWidget(Bewegend_Ton_Freq_erhoehen, 2, 2, 1, 1);

        Bewegend_Ton_Freq = new QSpinBox(Ton_tab);
        Bewegend_Ton_Freq->setObjectName("Bewegend_Ton_Freq");
        sizePolicy.setHeightForWidth(Bewegend_Ton_Freq->sizePolicy().hasHeightForWidth());
        Bewegend_Ton_Freq->setSizePolicy(sizePolicy);
        Bewegend_Ton_Freq->setFont(font2);
        Bewegend_Ton_Freq->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        Bewegend_Ton_Freq->setMouseTracking(false);
        Bewegend_Ton_Freq->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Bewegend_Ton_Freq->setFrame(false);
        Bewegend_Ton_Freq->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Bewegend_Ton_Freq->setReadOnly(false);
        Bewegend_Ton_Freq->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        Bewegend_Ton_Freq->setKeyboardTracking(false);
        Bewegend_Ton_Freq->setSuffix(QString::fromUtf8("%"));
        Bewegend_Ton_Freq->setMaximum(100);
        Bewegend_Ton_Freq->setSingleStep(5);

        Ton_Layout->addWidget(Bewegend_Ton_Freq, 3, 2, 1, 1);

        Bewegend_Ton_Freq_verringern = new QPushButton(Ton_tab);
        Bewegend_Ton_Freq_verringern->setObjectName("Bewegend_Ton_Freq_verringern");
        sizePolicy2.setHeightForWidth(Bewegend_Ton_Freq_verringern->sizePolicy().hasHeightForWidth());
        Bewegend_Ton_Freq_verringern->setSizePolicy(sizePolicy2);
        Bewegend_Ton_Freq_verringern->setMinimumSize(QSize(0, 40));
        Bewegend_Ton_Freq_verringern->setMaximumSize(QSize(16777215, 60));
        Bewegend_Ton_Freq_verringern->setIcon(icon1);

        Ton_Layout->addWidget(Bewegend_Ton_Freq_verringern, 4, 2, 1, 1);


        verticalLayout_5->addLayout(Ton_Layout);

        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Ton-icon-dark.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/Icons/Ton-icon-red.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        Sound_tabWidget->addTab(Ton_tab, icon2, QString());
        Beep_tab = new QWidget();
        Beep_tab->setObjectName("Beep_tab");
        Beep_tab->setAutoFillBackground(true);
        Beep_tab->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_8 = new QVBoxLayout(Beep_tab);
        verticalLayout_8->setObjectName("verticalLayout_8");
        Beep_Layout = new QGridLayout();
        Beep_Layout->setObjectName("Beep_Layout");
        Beep_Layout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        Beep_Layout->setHorizontalSpacing(20);
        Beep_Layout->setVerticalSpacing(4);
        Bewegend_Beep_Freq_verringern = new QPushButton(Beep_tab);
        Bewegend_Beep_Freq_verringern->setObjectName("Bewegend_Beep_Freq_verringern");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Bewegend_Beep_Freq_verringern->sizePolicy().hasHeightForWidth());
        Bewegend_Beep_Freq_verringern->setSizePolicy(sizePolicy4);
        Bewegend_Beep_Freq_verringern->setMinimumSize(QSize(0, 40));
        Bewegend_Beep_Freq_verringern->setMaximumSize(QSize(16777215, 60));
        Bewegend_Beep_Freq_verringern->setIcon(icon1);

        Beep_Layout->addWidget(Bewegend_Beep_Freq_verringern, 4, 2, 1, 1);

        Bewegend_Beep_Freq_Label = new QLabel(Beep_tab);
        Bewegend_Beep_Freq_Label->setObjectName("Bewegend_Beep_Freq_Label");
        Bewegend_Beep_Freq_Label->setFont(font2);
        Bewegend_Beep_Freq_Label->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Bewegend_Beep_Freq_Label->setAutoFillBackground(false);

        Beep_Layout->addWidget(Bewegend_Beep_Freq_Label, 1, 2, 1, 1);

        Bewegend_Beep_Freq_erhoehen = new QPushButton(Beep_tab);
        Bewegend_Beep_Freq_erhoehen->setObjectName("Bewegend_Beep_Freq_erhoehen");
        sizePolicy4.setHeightForWidth(Bewegend_Beep_Freq_erhoehen->sizePolicy().hasHeightForWidth());
        Bewegend_Beep_Freq_erhoehen->setSizePolicy(sizePolicy4);
        Bewegend_Beep_Freq_erhoehen->setMinimumSize(QSize(0, 40));
        Bewegend_Beep_Freq_erhoehen->setMaximumSize(QSize(16777215, 60));
        Bewegend_Beep_Freq_erhoehen->setIcon(icon);

        Beep_Layout->addWidget(Bewegend_Beep_Freq_erhoehen, 2, 2, 1, 1);

        Stillstehend_Beep_Freq_erhoehen = new QPushButton(Beep_tab);
        Stillstehend_Beep_Freq_erhoehen->setObjectName("Stillstehend_Beep_Freq_erhoehen");
        sizePolicy4.setHeightForWidth(Stillstehend_Beep_Freq_erhoehen->sizePolicy().hasHeightForWidth());
        Stillstehend_Beep_Freq_erhoehen->setSizePolicy(sizePolicy4);
        Stillstehend_Beep_Freq_erhoehen->setMinimumSize(QSize(0, 40));
        Stillstehend_Beep_Freq_erhoehen->setMaximumSize(QSize(16777215, 60));
        Stillstehend_Beep_Freq_erhoehen->setIcon(icon);

        Beep_Layout->addWidget(Stillstehend_Beep_Freq_erhoehen, 2, 0, 1, 1);

        Stillstehend_Beep_Freq_Label = new QLabel(Beep_tab);
        Stillstehend_Beep_Freq_Label->setObjectName("Stillstehend_Beep_Freq_Label");
        Stillstehend_Beep_Freq_Label->setFont(font2);
        Stillstehend_Beep_Freq_Label->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        Beep_Layout->addWidget(Stillstehend_Beep_Freq_Label, 1, 0, 1, 1);

        Bewegend_Beep_Freq = new QSpinBox(Beep_tab);
        Bewegend_Beep_Freq->setObjectName("Bewegend_Beep_Freq");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Bewegend_Beep_Freq->sizePolicy().hasHeightForWidth());
        Bewegend_Beep_Freq->setSizePolicy(sizePolicy5);
        Bewegend_Beep_Freq->setFont(font2);
        Bewegend_Beep_Freq->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        Bewegend_Beep_Freq->setMouseTracking(false);
        Bewegend_Beep_Freq->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Bewegend_Beep_Freq->setFrame(false);
        Bewegend_Beep_Freq->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Bewegend_Beep_Freq->setReadOnly(false);
        Bewegend_Beep_Freq->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        Bewegend_Beep_Freq->setKeyboardTracking(false);
        Bewegend_Beep_Freq->setSuffix(QString::fromUtf8("%"));
        Bewegend_Beep_Freq->setMaximum(100);
        Bewegend_Beep_Freq->setSingleStep(5);

        Beep_Layout->addWidget(Bewegend_Beep_Freq, 3, 2, 1, 1);

        Stillstehend_Beep_Freq = new QSpinBox(Beep_tab);
        Stillstehend_Beep_Freq->setObjectName("Stillstehend_Beep_Freq");
        sizePolicy.setHeightForWidth(Stillstehend_Beep_Freq->sizePolicy().hasHeightForWidth());
        Stillstehend_Beep_Freq->setSizePolicy(sizePolicy);
        Stillstehend_Beep_Freq->setFont(font2);
        Stillstehend_Beep_Freq->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        Stillstehend_Beep_Freq->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Stillstehend_Beep_Freq->setWrapping(false);
        Stillstehend_Beep_Freq->setFrame(false);
        Stillstehend_Beep_Freq->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Stillstehend_Beep_Freq->setReadOnly(false);
        Stillstehend_Beep_Freq->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        Stillstehend_Beep_Freq->setKeyboardTracking(false);
        Stillstehend_Beep_Freq->setMaximum(100);
        Stillstehend_Beep_Freq->setSingleStep(5);

        Beep_Layout->addWidget(Stillstehend_Beep_Freq, 3, 0, 1, 1);

        Stillstehend_Beep_Freq_verringern = new QPushButton(Beep_tab);
        Stillstehend_Beep_Freq_verringern->setObjectName("Stillstehend_Beep_Freq_verringern");
        sizePolicy4.setHeightForWidth(Stillstehend_Beep_Freq_verringern->sizePolicy().hasHeightForWidth());
        Stillstehend_Beep_Freq_verringern->setSizePolicy(sizePolicy4);
        Stillstehend_Beep_Freq_verringern->setMinimumSize(QSize(0, 40));
        Stillstehend_Beep_Freq_verringern->setMaximumSize(QSize(16777215, 60));
        Stillstehend_Beep_Freq_verringern->setIcon(icon1);

        Beep_Layout->addWidget(Stillstehend_Beep_Freq_verringern, 4, 0, 1, 1);

        line_2 = new QFrame(Beep_tab);
        line_2->setObjectName("line_2");
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        Beep_Layout->addWidget(line_2, 2, 1, 3, 1);


        verticalLayout_8->addLayout(Beep_Layout);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Beep-icon-dark.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon3.addFile(QString::fromUtf8(":/Icons/Beep-icon-red.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        Sound_tabWidget->addTab(Beep_tab, icon3, QString());

        verticalLayout_3->addWidget(Sound_tabWidget);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        pause_button = new QPushButton(Sound_Tab);
        pause_button->setObjectName("pause_button");
        pause_button->setMinimumSize(QSize(0, 80));
        QFont font4;
        font4.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        font4.setPointSize(20);
        font4.setBold(true);
        pause_button->setFont(font4);
        pause_button->setCheckable(true);
        pause_button->setChecked(false);

        verticalLayout_3->addWidget(pause_button);

        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/lautstarke_dark.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/Icons/lautstarke_red.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        icon4.addFile(QString::fromUtf8(":/Icons/lautstarke_red.png"), QSize(), QIcon::Mode::Selected, QIcon::State::On);
        tabWidget->addTab(Sound_Tab, icon4, QString());
        Light_Tab = new QWidget();
        Light_Tab->setObjectName("Light_Tab");
        verticalLayout_9 = new QVBoxLayout(Light_Tab);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(10, -1, 10, -1);
        Helligkeit_Layout = new QVBoxLayout();
        Helligkeit_Layout->setSpacing(4);
        Helligkeit_Layout->setObjectName("Helligkeit_Layout");
        Heilligkeit_Label = new QLabel(Light_Tab);
        Heilligkeit_Label->setObjectName("Heilligkeit_Label");
        sizePolicy1.setHeightForWidth(Heilligkeit_Label->sizePolicy().hasHeightForWidth());
        Heilligkeit_Label->setSizePolicy(sizePolicy1);
        Heilligkeit_Label->setFont(font1);
        Heilligkeit_Label->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        Helligkeit_Layout->addWidget(Heilligkeit_Label);

        Helligkeit_erhoehen = new QPushButton(Light_Tab);
        Helligkeit_erhoehen->setObjectName("Helligkeit_erhoehen");
        sizePolicy2.setHeightForWidth(Helligkeit_erhoehen->sizePolicy().hasHeightForWidth());
        Helligkeit_erhoehen->setSizePolicy(sizePolicy2);
        Helligkeit_erhoehen->setMinimumSize(QSize(0, 40));
        Helligkeit_erhoehen->setMaximumSize(QSize(16777215, 60));
        Helligkeit_erhoehen->setStyleSheet(QString::fromUtf8(""));
        Helligkeit_erhoehen->setIcon(icon);
        Helligkeit_erhoehen->setIconSize(QSize(40, 12));

        Helligkeit_Layout->addWidget(Helligkeit_erhoehen);

        Helligkeit = new QSpinBox(Light_Tab);
        Helligkeit->setObjectName("Helligkeit");
        sizePolicy3.setHeightForWidth(Helligkeit->sizePolicy().hasHeightForWidth());
        Helligkeit->setSizePolicy(sizePolicy3);
        Helligkeit->setFont(font2);
        Helligkeit->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        Helligkeit->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Helligkeit->setFrame(false);
        Helligkeit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Helligkeit->setReadOnly(false);
        Helligkeit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        Helligkeit->setKeyboardTracking(false);
        Helligkeit->setMaximum(100);
        Helligkeit->setSingleStep(5);

        Helligkeit_Layout->addWidget(Helligkeit);

        Heilligkeit_verringern = new QPushButton(Light_Tab);
        Heilligkeit_verringern->setObjectName("Heilligkeit_verringern");
        sizePolicy2.setHeightForWidth(Heilligkeit_verringern->sizePolicy().hasHeightForWidth());
        Heilligkeit_verringern->setSizePolicy(sizePolicy2);
        Heilligkeit_verringern->setMinimumSize(QSize(0, 40));
        Heilligkeit_verringern->setMaximumSize(QSize(16777215, 60));
        Heilligkeit_verringern->setIcon(icon1);

        Helligkeit_Layout->addWidget(Heilligkeit_verringern);

        Helligkeit_Layout->setStretch(0, 4);
        Helligkeit_Layout->setStretch(1, 4);
        Helligkeit_Layout->setStretch(2, 4);
        Helligkeit_Layout->setStretch(3, 4);

        verticalLayout_9->addLayout(Helligkeit_Layout);

        Farbe_Label = new QLabel(Light_Tab);
        Farbe_Label->setObjectName("Farbe_Label");

        verticalLayout_9->addWidget(Farbe_Label);

        StillstehendColorSelectionGroupBox = new QGroupBox(Light_Tab);
        StillstehendColorSelectionGroupBox->setObjectName("StillstehendColorSelectionGroupBox");
        StillstehendColorSelectionGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color: transparent;\n"
"\n"
"}"));
        verticalLayout_11 = new QVBoxLayout(StillstehendColorSelectionGroupBox);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        Stillstehend_Farbe1 = new QRadioButton(StillstehendColorSelectionGroupBox);
        Stillstehend_Farbe1->setObjectName("Stillstehend_Farbe1");
        Stillstehend_Farbe1->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"QRadioButton::indicator{\n"
"	background-color: white;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"\n"
"}\n"
"\n"
""));
        Stillstehend_Farbe1->setCheckable(true);
        Stillstehend_Farbe1->setChecked(false);

        gridLayout_6->addWidget(Stillstehend_Farbe1, 1, 0, 1, 1);

        Stillstehend_Farbe2 = new QRadioButton(StillstehendColorSelectionGroupBox);
        Stillstehend_Farbe2->setObjectName("Stillstehend_Farbe2");
        Stillstehend_Farbe2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"QRadioButton::indicator{\n"
"	background-color: red;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
""));

        gridLayout_6->addWidget(Stillstehend_Farbe2, 1, 1, 1, 1);

        Stillstehend_Farbe4 = new QRadioButton(StillstehendColorSelectionGroupBox);
        Stillstehend_Farbe4->setObjectName("Stillstehend_Farbe4");
        Stillstehend_Farbe4->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"	background-color: rgb(0, 255, 0);\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
""));

        gridLayout_6->addWidget(Stillstehend_Farbe4, 1, 2, 1, 1);

        Stillstehend_Farbe3 = new QRadioButton(StillstehendColorSelectionGroupBox);
        Stillstehend_Farbe3->setObjectName("Stillstehend_Farbe3");
        Stillstehend_Farbe3->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"\n"
"	\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"QRadioButton::indicator{\n"
"	background-color: blue;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
"\n"
""));

        gridLayout_6->addWidget(Stillstehend_Farbe3, 1, 3, 1, 1);

        Stillstehend_Farbe5 = new QRadioButton(StillstehendColorSelectionGroupBox);
        Stillstehend_Farbe5->setObjectName("Stillstehend_Farbe5");
        Stillstehend_Farbe5->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"	background-color: yellow;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
""));

        gridLayout_6->addWidget(Stillstehend_Farbe5, 1, 4, 1, 1);

        Stillstehend_Farbe_label = new QLabel(StillstehendColorSelectionGroupBox);
        Stillstehend_Farbe_label->setObjectName("Stillstehend_Farbe_label");
        Stillstehend_Farbe_label->setFont(font3);
        Stillstehend_Farbe_label->setStyleSheet(QString::fromUtf8("QLabel{background: rgb(0, 0, 0);\n"
"margin-top: 5px;\n"
"margin-left: 5px;\n"
"margin-right: 5px;\n"
"border-radius: 6px;\n"
"}"));

        gridLayout_6->addWidget(Stillstehend_Farbe_label, 0, 0, 1, 5);


        verticalLayout_11->addLayout(gridLayout_6);


        verticalLayout_9->addWidget(StillstehendColorSelectionGroupBox);

        BewegendColorSelectionGroupBox = new QGroupBox(Light_Tab);
        BewegendColorSelectionGroupBox->setObjectName("BewegendColorSelectionGroupBox");
        BewegendColorSelectionGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color: transparent;\n"
"\n"
"}"));
        verticalLayout_12 = new QVBoxLayout(BewegendColorSelectionGroupBox);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        Bewegend_Farbe_Label = new QLabel(BewegendColorSelectionGroupBox);
        Bewegend_Farbe_Label->setObjectName("Bewegend_Farbe_Label");

        gridLayout_3->addWidget(Bewegend_Farbe_Label, 0, 0, 1, 5);

        Bewegend_Farbe1 = new QRadioButton(BewegendColorSelectionGroupBox);
        Bewegend_Farbe1->setObjectName("Bewegend_Farbe1");
        Bewegend_Farbe1->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"	background-color: white;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: 2px solid #868686;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
"\n"
""));
        Bewegend_Farbe1->setCheckable(true);
        Bewegend_Farbe1->setChecked(false);

        gridLayout_3->addWidget(Bewegend_Farbe1, 1, 0, 1, 1);

        Bewegend_Farbe2 = new QRadioButton(BewegendColorSelectionGroupBox);
        Bewegend_Farbe2->setObjectName("Bewegend_Farbe2");
        Bewegend_Farbe2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"QRadioButton::indicator{\n"
"	background-color: red;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
""));

        gridLayout_3->addWidget(Bewegend_Farbe2, 1, 1, 1, 1);

        Bewegend_Farbe4 = new QRadioButton(BewegendColorSelectionGroupBox);
        Bewegend_Farbe4->setObjectName("Bewegend_Farbe4");
        Bewegend_Farbe4->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"	background-color: rgb(0, 255, 0);\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
""));

        gridLayout_3->addWidget(Bewegend_Farbe4, 1, 2, 1, 1);

        Bewegend_Farbe3 = new QRadioButton(BewegendColorSelectionGroupBox);
        Bewegend_Farbe3->setObjectName("Bewegend_Farbe3");
        Bewegend_Farbe3->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"QRadioButton::indicator{\n"
"	background-color: blue;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
"\n"
""));

        gridLayout_3->addWidget(Bewegend_Farbe3, 1, 3, 1, 1);

        Bewegend_Farbe5 = new QRadioButton(BewegendColorSelectionGroupBox);
        Bewegend_Farbe5->setObjectName("Bewegend_Farbe5");
        Bewegend_Farbe5->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	background-color: none;\n"
"	margin-top: 10px;\n"
"	margin-bottom: 10px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"	background-color: yellow;\n"
"	width: 40px;\n"
"	height: 40px;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"        border: 4px solid black;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"        border: 2px solid #868686;\n"
"}\n"
""));

        gridLayout_3->addWidget(Bewegend_Farbe5, 1, 4, 1, 1);


        verticalLayout_12->addLayout(gridLayout_3);


        verticalLayout_9->addWidget(BewegendColorSelectionGroupBox);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);

        verticalSpacer_6 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_6);

        pause_button2 = new QPushButton(Light_Tab);
        pause_button2->setObjectName("pause_button2");
        pause_button2->setMinimumSize(QSize(0, 80));
        pause_button2->setFont(font2);
        pause_button2->setCheckable(true);

        verticalLayout_9->addWidget(pause_button2);

        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/light_icon_light.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon5.addFile(QString::fromUtf8(":/Icons/light-icon_red.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        tabWidget->addTab(Light_Tab, icon5, QString());
        Profile_Tab = new QWidget();
        Profile_Tab->setObjectName("Profile_Tab");
        Profile_Tab->setEnabled(false);
        sizePolicy5.setHeightForWidth(Profile_Tab->sizePolicy().hasHeightForWidth());
        Profile_Tab->setSizePolicy(sizePolicy5);
        Profile_Tab->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        verticalLayout_4 = new QVBoxLayout(Profile_Tab);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(10, -1, 10, -1);
        stackedWidget = new QStackedWidget(Profile_Tab);
        stackedWidget->setObjectName("stackedWidget");
        Profil_page = new QWidget();
        Profil_page->setObjectName("Profil_page");
        gridLayout = new QGridLayout(Profil_page);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(Profil_page);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 416, 560));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        profil_from_currentsettings_button = new QPushButton(Profil_page);
        profil_from_currentsettings_button->setObjectName("profil_from_currentsettings_button");
        profil_from_currentsettings_button->setMinimumSize(QSize(0, 50));
        profil_from_currentsettings_button->setFont(font3);

        gridLayout->addWidget(profil_from_currentsettings_button, 1, 0, 1, 1);

        delete_current_profile_button = new QPushButton(Profil_page);
        delete_current_profile_button->setObjectName("delete_current_profile_button");
        sizePolicy1.setHeightForWidth(delete_current_profile_button->sizePolicy().hasHeightForWidth());
        delete_current_profile_button->setSizePolicy(sizePolicy1);
        delete_current_profile_button->setMinimumSize(QSize(0, 50));
        delete_current_profile_button->setFont(font3);

        gridLayout->addWidget(delete_current_profile_button, 2, 0, 1, 1);

        stackedWidget->addWidget(Profil_page);
        profil_from_currentsettings_button->raise();
        scrollArea->raise();
        delete_current_profile_button->raise();
        new_profile_page = new QWidget();
        new_profile_page->setObjectName("new_profile_page");
        verticalLayout_7 = new QVBoxLayout(new_profile_page);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        new_profile_label = new QLabel(new_profile_page);
        new_profile_label->setObjectName("new_profile_label");
        new_profile_label->setFont(font2);

        verticalLayout_7->addWidget(new_profile_label);

        new_profile_lineEdit = new QLineEdit(new_profile_page);
        new_profile_lineEdit->setObjectName("new_profile_lineEdit");
        QFont font5;
        font5.setPointSize(16);
        new_profile_lineEdit->setFont(font5);

        verticalLayout_7->addWidget(new_profile_lineEdit);

        new_profile_button = new QPushButton(new_profile_page);
        new_profile_button->setObjectName("new_profile_button");
        new_profile_button->setFont(font5);

        verticalLayout_7->addWidget(new_profile_button);

        new_profile_volume_label = new QLabel(new_profile_page);
        new_profile_volume_label->setObjectName("new_profile_volume_label");
        new_profile_volume_label->setFont(font5);

        verticalLayout_7->addWidget(new_profile_volume_label);

        new_profile_Bew_Freq_label = new QLabel(new_profile_page);
        new_profile_Bew_Freq_label->setObjectName("new_profile_Bew_Freq_label");
        new_profile_Bew_Freq_label->setFont(font5);

        verticalLayout_7->addWidget(new_profile_Bew_Freq_label);

        new_profile_Still_Freq_label = new QLabel(new_profile_page);
        new_profile_Still_Freq_label->setObjectName("new_profile_Still_Freq_label");
        new_profile_Still_Freq_label->setFont(font5);

        verticalLayout_7->addWidget(new_profile_Still_Freq_label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        new_profile_cancle_button = new QPushButton(new_profile_page);
        new_profile_cancle_button->setObjectName("new_profile_cancle_button");

        verticalLayout_7->addWidget(new_profile_cancle_button);

        stackedWidget->addWidget(new_profile_page);
        edit_profile_page = new QWidget();
        edit_profile_page->setObjectName("edit_profile_page");
        stackedWidget->addWidget(edit_profile_page);

        verticalLayout_4->addWidget(stackedWidget);

        tabWidget->addTab(Profile_Tab, QString());
        Ball_Tab = new QWidget();
        Ball_Tab->setObjectName("Ball_Tab");
        verticalLayout_6 = new QVBoxLayout(Ball_Tab);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(10, -1, 10, -1);
        UIDeviceList = new QListWidget(Ball_Tab);
        UIDeviceList->setObjectName("UIDeviceList");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(UIDeviceList->sizePolicy().hasHeightForWidth());
        UIDeviceList->setSizePolicy(sizePolicy6);

        verticalLayout_6->addWidget(UIDeviceList);

        label = new QLabel(Ball_Tab);
        label->setObjectName("label");
        QFont font6;
        font6.setPointSize(14);
        label->setFont(font6);
        label->setWordWrap(true);

        verticalLayout_6->addWidget(label);

        searchKlingelball = new QPushButton(Ball_Tab);
        searchKlingelball->setObjectName("searchKlingelball");
        searchKlingelball->setMinimumSize(QSize(0, 50));
        QFont font7;
        font7.setPointSize(18);
        searchKlingelball->setFont(font7);

        verticalLayout_6->addWidget(searchKlingelball);

        disconnectKlingelball = new QPushButton(Ball_Tab);
        disconnectKlingelball->setObjectName("disconnectKlingelball");
        disconnectKlingelball->setMinimumSize(QSize(0, 50));
        disconnectKlingelball->setFont(font7);

        verticalLayout_6->addWidget(disconnectKlingelball);

        OnOff_Button = new QPushButton(Ball_Tab);
        OnOff_Button->setObjectName("OnOff_Button");
        OnOff_Button->setMinimumSize(QSize(0, 50));
        QFont font8;
        font8.setPointSize(18);
        font8.setBold(false);
        OnOff_Button->setFont(font8);
        OnOff_Button->setStyleSheet(QString::fromUtf8("QPushButton:!checked{\n"
"	background-color: #e50616;\n"
"}\n"
"\n"
"QPushButton::checked{\n"
"	background-color: #00aa00;\n"
"}\n"
"\n"
""));
        OnOff_Button->setCheckable(true);
        OnOff_Button->setChecked(true);

        verticalLayout_6->addWidget(OnOff_Button);

        batteryStatusProgressbar = new QProgressBar(Ball_Tab);
        batteryStatusProgressbar->setObjectName("batteryStatusProgressbar");
        QFont font9;
        font9.setBold(true);
        batteryStatusProgressbar->setFont(font9);
        batteryStatusProgressbar->setStyleSheet(QString::fromUtf8(""));
        batteryStatusProgressbar->setValue(50);
        batteryStatusProgressbar->setInvertedAppearance(false);

        verticalLayout_6->addWidget(batteryStatusProgressbar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/Ball_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon6.addFile(QString::fromUtf8(":/Icons/ball_icon_red.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        tabWidget->addTab(Ball_Tab, icon6, QString());
        Settings_Tab = new QWidget();
        Settings_Tab->setObjectName("Settings_Tab");
        verticalLayout_10 = new QVBoxLayout(Settings_Tab);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(10, -1, 10, -1);
        Aussehen_label = new QLabel(Settings_Tab);
        Aussehen_label->setObjectName("Aussehen_label");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(Aussehen_label->sizePolicy().hasHeightForWidth());
        Aussehen_label->setSizePolicy(sizePolicy7);
        Aussehen_label->setSizeIncrement(QSize(0, 0));
        QFont font10;
        font10.setPointSize(28);
        font10.setBold(true);
        Aussehen_label->setFont(font10);
        Aussehen_label->setStyleSheet(QString::fromUtf8(""));
        Aussehen_label->setFrameShape(QFrame::Shape::NoFrame);
        Aussehen_label->setWordWrap(false);
        Aussehen_label->setIndent(-1);

        verticalLayout_10->addWidget(Aussehen_label);

        Automatic_checkBox = new QCheckBox(Settings_Tab);
        Automatic_checkBox->setObjectName("Automatic_checkBox");
        QFont font11;
        font11.setPointSize(22);
        font11.setBold(true);
        Automatic_checkBox->setFont(font11);
        Automatic_checkBox->setChecked(true);

        verticalLayout_10->addWidget(Automatic_checkBox);

        Lightmode_checkBox = new QCheckBox(Settings_Tab);
        Lightmode_checkBox->setObjectName("Lightmode_checkBox");
        Lightmode_checkBox->setFont(font11);
        Lightmode_checkBox->setIconSize(QSize(20, 20));
        Lightmode_checkBox->setChecked(false);
        Lightmode_checkBox->setTristate(false);

        verticalLayout_10->addWidget(Lightmode_checkBox);

        Darkmode_checkBox = new QCheckBox(Settings_Tab);
        Darkmode_checkBox->setObjectName("Darkmode_checkBox");
        Darkmode_checkBox->setFont(font11);
        Darkmode_checkBox->setIconSize(QSize(20, 20));
        Darkmode_checkBox->setChecked(false);
        Darkmode_checkBox->setTristate(false);

        verticalLayout_10->addWidget(Darkmode_checkBox);

        Erklaerung_textView = new QTextBrowser(Settings_Tab);
        Erklaerung_textView->setObjectName("Erklaerung_textView");
        Erklaerung_textView->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        Erklaerung_textView->setStyleSheet(QString::fromUtf8("QTextBrowser{\n"
"	background-color: white;\n"
"}"));
        Erklaerung_textView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        Erklaerung_textView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        Erklaerung_textView->setOpenExternalLinks(true);

        verticalLayout_10->addWidget(Erklaerung_textView);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_9);

        verticalSpacer_10 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_10);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/settings_icon_176440.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon7.addFile(QString::fromUtf8(":/Icons/settings_icon_red.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        tabWidget->addTab(Settings_Tab, icon7, QString());

        verticalLayout_2->addWidget(tabWidget);

        KlingelballUI->setCentralWidget(centralwidget);
#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(tabWidget, Lautstaerke);
        QWidget::setTabOrder(Lautstaerke, Lautstaerke_erhoehen);
        QWidget::setTabOrder(Lautstaerke_erhoehen, Lautstaerke_verringern);
        QWidget::setTabOrder(Lautstaerke_verringern, Helligkeit_erhoehen);
        QWidget::setTabOrder(Helligkeit_erhoehen, Heilligkeit_verringern);
        QWidget::setTabOrder(Heilligkeit_verringern, profil_from_currentsettings_button);
        QWidget::setTabOrder(profil_from_currentsettings_button, new_profile_button);
        QWidget::setTabOrder(new_profile_button, UIDeviceList);
        QWidget::setTabOrder(UIDeviceList, searchKlingelball);
        QWidget::setTabOrder(searchKlingelball, disconnectKlingelball);
        QWidget::setTabOrder(disconnectKlingelball, OnOff_Button);
        QWidget::setTabOrder(OnOff_Button, Lightmode_checkBox);
        QWidget::setTabOrder(Lightmode_checkBox, Darkmode_checkBox);
        QWidget::setTabOrder(Darkmode_checkBox, new_profile_cancle_button);
        QWidget::setTabOrder(new_profile_cancle_button, delete_current_profile_button);
        QWidget::setTabOrder(delete_current_profile_button, new_profile_lineEdit);
        QWidget::setTabOrder(new_profile_lineEdit, Stillstehend_Beep_Freq_Label);
        QWidget::setTabOrder(Stillstehend_Beep_Freq_Label, Stillstehend_Beep_Freq_erhoehen);
        QWidget::setTabOrder(Stillstehend_Beep_Freq_erhoehen, Stillstehend_Beep_Freq_verringern);
        QWidget::setTabOrder(Stillstehend_Beep_Freq_verringern, Bewegend_Beep_Freq_Label);
        QWidget::setTabOrder(Bewegend_Beep_Freq_Label, Bewegend_Beep_Freq_erhoehen);
        QWidget::setTabOrder(Bewegend_Beep_Freq_erhoehen, Bewegend_Beep_Freq_verringern);
        QWidget::setTabOrder(Bewegend_Beep_Freq_verringern, Stillstehend_Farbe1);
        QWidget::setTabOrder(Stillstehend_Farbe1, Stillstehend_Farbe2);
        QWidget::setTabOrder(Stillstehend_Farbe2, Stillstehend_Farbe4);
        QWidget::setTabOrder(Stillstehend_Farbe4, Stillstehend_Farbe3);
        QWidget::setTabOrder(Stillstehend_Farbe3, Stillstehend_Farbe5);
        QWidget::setTabOrder(Stillstehend_Farbe5, Sound_tabWidget);
        QWidget::setTabOrder(Sound_tabWidget, scrollArea);

        retranslateUi(KlingelballUI);
        QObject::connect(Stillstehend_Ton_Freq_Verringern, &QPushButton::clicked, Stillstehend_Ton_Freq, qOverload<>(&QSpinBox::stepDown));
        QObject::connect(Bewegend_Ton_Freq_verringern, &QPushButton::clicked, Bewegend_Ton_Freq, qOverload<>(&QSpinBox::stepDown));
        QObject::connect(Bewegend_Ton_Freq_erhoehen, &QPushButton::clicked, Bewegend_Ton_Freq, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(Stillstehend_Ton_Freq_erhoehen, &QPushButton::clicked, Stillstehend_Ton_Freq, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(Stillstehend_Beep_Freq_erhoehen, &QPushButton::clicked, Stillstehend_Beep_Freq, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(Stillstehend_Beep_Freq_verringern, &QPushButton::clicked, Stillstehend_Beep_Freq, qOverload<>(&QSpinBox::stepDown));
        QObject::connect(Bewegend_Beep_Freq_erhoehen, &QPushButton::clicked, Bewegend_Beep_Freq, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(Bewegend_Beep_Freq_verringern, &QPushButton::clicked, Bewegend_Beep_Freq, qOverload<>(&QSpinBox::stepDown));
        QObject::connect(pause_button2, &QPushButton::clicked, pause_button, qOverload<>(&QPushButton::click));
        QObject::connect(OnOff_Button, &QPushButton::toggled, pause_button, qOverload<>(&QPushButton::toggle));
        QObject::connect(Lautstaerke_erhoehen, &QPushButton::clicked, Lautstaerke, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(Lautstaerke_verringern, &QPushButton::clicked, Lautstaerke, qOverload<>(&QSpinBox::stepDown));
        QObject::connect(Helligkeit_erhoehen, &QPushButton::clicked, Helligkeit, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(Heilligkeit_verringern, &QPushButton::clicked, Helligkeit, qOverload<>(&QSpinBox::stepDown));

        tabWidget->setCurrentIndex(0);
        Sound_tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);
        UIDeviceList->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(KlingelballUI);
    } // setupUi

    void retranslateUi(QMainWindow *KlingelballUI)
    {
        KlingelballUI->setWindowTitle(QCoreApplication::translate("KlingelballUI", "KlingelballUI", nullptr));
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Sound_Tab->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Sound_Tab->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Lautstaerke_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Lautst\303\244rke \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Lautstaerke_Label->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        Lautstaerke_Label->setText(QCoreApplication::translate("KlingelballUI", "Lautst\303\244rke", nullptr));
#if QT_CONFIG(accessibility)
        Lautstaerke_erhoehen->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Lautst\303\244rke um 5% erh\303\266hen Taste", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Lautstaerke_erhoehen->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        Lautstaerke_erhoehen->setText(QString());
#if QT_CONFIG(accessibility)
        Lautstaerke->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Lautst\303\244rke %", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Lautstaerke->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        Lautstaerke->setSuffix(QCoreApplication::translate("KlingelballUI", "%", nullptr));
#if QT_CONFIG(accessibility)
        Lautstaerke_verringern->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Lautst\303\244rke um 5% verringern Taste", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Lautstaerke_verringern->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        Lautstaerke_verringern->setText(QString());
#if QT_CONFIG(accessibility)
        Sound_tabWidget->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Frequenzeinstellungen", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Sound_tabWidget->setAccessibleDescription(QCoreApplication::translate("KlingelballUI", "Tabbereich", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehend Tonh\303\266he \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq_Label->setText(QCoreApplication::translate("KlingelballUI", "Stillstehend:", nullptr));
#if QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq_erhoehen->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehende Tonfrequenz um 5% erh\303\266hen Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq_erhoehen->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehende Frequenz %", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq->setSuffix(QCoreApplication::translate("KlingelballUI", "%", nullptr));
#if QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq_Verringern->setAccessibleName(QCoreApplication::translate("KlingelballUI", "StillstehendeTonfrequenz um 5% verringern Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Ton_Freq_Verringern->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Ton_Freq_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegend Tonh\303\266he \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Ton_Freq_Label->setText(QCoreApplication::translate("KlingelballUI", "Bewegend:", nullptr));
#if QT_CONFIG(accessibility)
        Bewegend_Ton_Freq_erhoehen->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegende Tonfrequenz um 5% erh\303\266hen Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Ton_Freq_erhoehen->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Ton_Freq->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegende Tonfrequenz %", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Bewegend_Ton_Freq_verringern->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegende Tonfrequenz um 5% verringern Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Ton_Freq_verringern->setText(QString());
        Sound_tabWidget->setTabText(Sound_tabWidget->indexOf(Ton_tab), QCoreApplication::translate("KlingelballUI", "Tonh\303\266he", nullptr));
#if QT_CONFIG(accessibility)
        Bewegend_Beep_Freq_verringern->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegende Piepsfrequenz um 5% verringern Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Beep_Freq_verringern->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Beep_Freq_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegend Piepsen \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Beep_Freq_Label->setText(QCoreApplication::translate("KlingelballUI", "Bewegend:", nullptr));
#if QT_CONFIG(accessibility)
        Bewegend_Beep_Freq_erhoehen->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegende Piepsfrequenz um 5% erh\303\266hen Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Beep_Freq_erhoehen->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq_erhoehen->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehende Piepsfrequenz um 5% erh\303\266hen Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq_erhoehen->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehend Piepsen \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq_Label->setText(QCoreApplication::translate("KlingelballUI", "Stillstehend:", nullptr));
#if QT_CONFIG(accessibility)
        Bewegend_Beep_Freq->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegende Piepsfrequenz %", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehende Piepsrequenz %", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq->setSuffix(QCoreApplication::translate("KlingelballUI", "%", nullptr));
#if QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq_verringern->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehende Piepsrequenz um 5% verringern Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Beep_Freq_verringern->setText(QString());
        Sound_tabWidget->setTabText(Sound_tabWidget->indexOf(Beep_tab), QCoreApplication::translate("KlingelballUI", "Piepsen", nullptr));
#if QT_CONFIG(accessibility)
        pause_button->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stopp taste", nullptr));
#endif // QT_CONFIG(accessibility)
        pause_button->setText(QCoreApplication::translate("KlingelballUI", "Stopp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Sound_Tab), QString());
#if QT_CONFIG(accessibility)
        Light_Tab->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Light_Tab->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Heilligkeit_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Helligkeit \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Heilligkeit_Label->setText(QCoreApplication::translate("KlingelballUI", "Helligkeit", nullptr));
#if QT_CONFIG(accessibility)
        Helligkeit_erhoehen->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Helligkeit um 5% erh\303\266hen ", nullptr));
#endif // QT_CONFIG(accessibility)
        Helligkeit_erhoehen->setText(QString());
#if QT_CONFIG(accessibility)
        Helligkeit->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Helligkeit %", nullptr));
#endif // QT_CONFIG(accessibility)
        Helligkeit->setSuffix(QCoreApplication::translate("KlingelballUI", "%", nullptr));
#if QT_CONFIG(accessibility)
        Heilligkeit_verringern->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Helligkeit um 5% verringern", nullptr));
#endif // QT_CONFIG(accessibility)
        Heilligkeit_verringern->setText(QString());
#if QT_CONFIG(accessibility)
        Farbe_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Farbauswahl \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Farbe_Label->setText(QCoreApplication::translate("KlingelballUI", "Farbe:", nullptr));
        StillstehendColorSelectionGroupBox->setTitle(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Farbe1->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Wei\303\237 Stillstehend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Farbe1->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Farbe2->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Rot Stillstehend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Farbe2->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Farbe4->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Gr\303\274n Stillstehend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Farbe4->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Farbe3->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Blau Stillstehend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Farbe3->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Farbe5->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Gelb Stillstehend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Farbe5->setText(QString());
#if QT_CONFIG(accessibility)
        Stillstehend_Farbe_label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stillstehend Farbauswahl \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Stillstehend_Farbe_label->setText(QCoreApplication::translate("KlingelballUI", "Stillstehend:", nullptr));
        BewegendColorSelectionGroupBox->setTitle(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Farbe_Label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Bewegend Farbauswahl \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Farbe_Label->setText(QCoreApplication::translate("KlingelballUI", "Bewegend:", nullptr));
#if QT_CONFIG(accessibility)
        Bewegend_Farbe1->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Wei\303\237 Bewegend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Farbe1->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Farbe2->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Rot Bewegend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Farbe2->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Farbe4->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Gr\303\274n Bewegend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Farbe4->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Farbe3->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Blau Bewegend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Farbe3->setText(QString());
#if QT_CONFIG(accessibility)
        Bewegend_Farbe5->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Gelb Bewegend Farbwahl nicht aktiviert", nullptr));
#endif // QT_CONFIG(accessibility)
        Bewegend_Farbe5->setText(QString());
#if QT_CONFIG(accessibility)
        pause_button2->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Stopp taste", nullptr));
#endif // QT_CONFIG(accessibility)
        pause_button2->setText(QCoreApplication::translate("KlingelballUI", "Stopp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Light_Tab), QString());
        profil_from_currentsettings_button->setText(QCoreApplication::translate("KlingelballUI", "Neues Profil aus aktuellen Einstellungen", nullptr));
        delete_current_profile_button->setText(QCoreApplication::translate("KlingelballUI", "Ausgew\303\244hltes Profil l\303\266schen", nullptr));
        new_profile_label->setText(QCoreApplication::translate("KlingelballUI", "Profil-Name:", nullptr));
#if QT_CONFIG(accessibility)
        new_profile_lineEdit->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Profilname eingabe", nullptr));
#endif // QT_CONFIG(accessibility)
        new_profile_button->setText(QCoreApplication::translate("KlingelballUI", "Neues Profil erstellen", nullptr));
        new_profile_volume_label->setText(QCoreApplication::translate("KlingelballUI", "Lautst\303\244rke: ", nullptr));
        new_profile_Bew_Freq_label->setText(QCoreApplication::translate("KlingelballUI", "Frequenz-Bewegend:", nullptr));
        new_profile_Still_Freq_label->setText(QCoreApplication::translate("KlingelballUI", "Frequenz-Stillstehend: ", nullptr));
        new_profile_cancle_button->setText(QCoreApplication::translate("KlingelballUI", "Abbrechen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Profile_Tab), QCoreApplication::translate("KlingelballUI", "Profile", nullptr));
#if QT_CONFIG(accessibility)
        Ball_Tab->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        Ball_Tab->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        UIDeviceList->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Verf\303\274gbare Klingelb\303\244lle Liste", nullptr));
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("KlingelballUI", "Hier werden alle verf\303\274gbaren Klingelb\303\244lle angezeigt. Stelle sicher, dass Bluetooth und Standort f\303\274r die App aktiviert ist. ", nullptr));
#if QT_CONFIG(accessibility)
        searchKlingelball->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Klingelball suchen Taste", nullptr));
#endif // QT_CONFIG(accessibility)
        searchKlingelball->setText(QCoreApplication::translate("KlingelballUI", "Klingelball suchen", nullptr));
#if QT_CONFIG(accessibility)
        disconnectKlingelball->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Klingelball trennen taste", nullptr));
#endif // QT_CONFIG(accessibility)
        disconnectKlingelball->setText(QCoreApplication::translate("KlingelballUI", "Klingelball trennen", nullptr));
#if QT_CONFIG(accessibility)
        OnOff_Button->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        OnOff_Button->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        OnOff_Button->setText(QCoreApplication::translate("KlingelballUI", "Ball: Ein", nullptr));
#if QT_CONFIG(accessibility)
        batteryStatusProgressbar->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Akku Stand", nullptr));
#endif // QT_CONFIG(accessibility)
        batteryStatusProgressbar->setFormat(QCoreApplication::translate("KlingelballUI", "Akkustand: %p%", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Ball_Tab), QString());
#if QT_CONFIG(accessibility)
        Aussehen_label->setAccessibleName(QCoreApplication::translate("KlingelballUI", "Aussehen \303\234berschrift", nullptr));
#endif // QT_CONFIG(accessibility)
        Aussehen_label->setText(QCoreApplication::translate("KlingelballUI", "Aussehen:", nullptr));
        Automatic_checkBox->setText(QCoreApplication::translate("KlingelballUI", "Automatisch", nullptr));
        Lightmode_checkBox->setText(QCoreApplication::translate("KlingelballUI", "Heller Modus", nullptr));
        Darkmode_checkBox->setText(QCoreApplication::translate("KlingelballUI", "Dunkler Modus", nullptr));
        Erklaerung_textView->setHtml(QCoreApplication::translate("KlingelballUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a name=\"WACViewPanel_ClipboardElement\"></a><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:18pt; font-weight:700; color:#000000;\">E</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:18pt; font-we"
                        "ight:700; color:#000000;\">rkl\303\244rung zur Barrierefreiheit</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:18pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Die Universit\303\244t Wien ist bem\303\274ht, ihre mobile Anwendung im Einklang mit dem Bundesgesetz \303\274ber den barrierefreien Zugang zu Websites und mobilen Anwendungen des Bundes (Web-Zug\303\244nglichkeits-Gesetz \342\200\223 WZG) BGBl. I. Nr. 59/2019 idgF, barrierefrei zug\303\244nglich zu machen.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transpar"
                        "ent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Diese Erkl\303\244rung zur Barrierefreiheit gilt f\303\274r die mobile Anwendung </span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000; background-color:transparent;\">Klingelball.</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; font-weight:700; color:#000000;\">Stand der Vereinbarkeit mit den Anforderungen</span><span style=\" font-family:'Times"
                        " New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Diese mobile Anwendung</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; font-style:italic; color:#000000;\"> ist</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\"> mit der Konformit\303\244tsstufe AA der \342\200\236Richtlinien f\303\274r barrierefreie Webinhalte \342\200\223 WCAG 2.1\342\200\234 beziehungsweise mit dem geltenden Europ\303\244ischen Standard EN 301 549 V3.2.1 (202"
                        "1-03) nach der Richtlinie (EU) 2016/2102 des Europ\303\244ischen Parlaments und des Rates vollst\303\244ndig vereinbar. \302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; font-weight:700; color:#000000;\">Erstellung der Erkl\303\244rung zur Barrierefreiheit</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Diese Erkl\303\244run"
                        "g wurde am 26. Februar 2024 erstellt.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Die Erkl\303\244rung wurde auf Grundlage einer von einer der Universit\303\244t Wien durchgef\303\274hrten Selbstbewertung erstellt.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Diese Erkl\303\244rung wurde zuletzt am 26. Februar 2024 \303\274berpr\303\274ft.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; font-weight:700; color:#000000;\">Feedback und Kontaktangaben</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Sie k\303\266nnen M\303\244ngel in Bezug auf die Einhaltung der Barrierefreiheitsanforderungen unter </span><a href=\"mailto:smart.isw@univie.ac.at\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; text"
                        "-decoration: underline; color:#0000ff;\">smart.isw@univie.ac.at</span></a><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\"> bekanntgeben.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; font-weight:700; color:#000000;\">Durchsetzungsverfahren</span><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:13.5pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times "
                        "New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Bei nicht zufriedenstellenden Antworten aus oben genannter Kontaktm\303\266glichkeit k\303\266nnen Sie sich mittels Beschwerde an die Beschwerdestelle der \303\226sterreichische Forschungsf\303\266rderungsgesellschaft mit beschr\303\244nkter Haftung (FFG) wenden. Die FFG nimmt \303\274ber das </span><a href=\"https://www.ffg.at/form/kontaktformular-beschwerdestelle\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; text-decoration: underline; color:#0000ff;\">Kontaktformular der Beschwerdestelle</span></a><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\"> Beschwerden auf elektronischem Weg entgegen.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transp"
                        "arent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Die Beschwerden werden von der FFG dahingehend gepr\303\274ft, ob sie sich auf Verst\303\266\303\237e gegen die Vorgaben des Web-Zug\303\244nglichkeits-Gesetzes, insbesondere M\303\244ngel bei der Einhaltung der Barrierefreiheitsanforderungen, durch den Bund oder einer ihm zuordenbaren Einrichtung beziehen.\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">Sofern die Beschwerde berechtigt ist, hat die FFG dem Bund oder den betroffenen Rechtstr\303\244gern Handlungsempfehlungen auszusprechen und Ma\303\237nahmen vorzuschlagen, die der Beseitigung der vorliegenden M\303\244ngel dienen."
                        "\302\240</span></p>\n"
"<p style=\" margin-top:37px; margin-bottom:37px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a href=\"https://www.ffg.at/barrierefreiheit/beschwerdestelle\"><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; text-decoration: underline; color:#0000ff;\">Weitere Informationen zum Beschwerdeverfahren</span></a><span style=\" font-family:'Times New Roman','Times New Roman_EmbeddedFont','Times New Roman_MSFontService','serif'; font-size:12pt; color:#000000;\">\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:11px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Calibri','Calibri_EmbeddedFont','Calibri_MSFontService','sans-serif'; font-size:11pt; color:#000000;\">\302\240</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Settings_Tab), QString());
    } // retranslateUi

};

namespace Ui {
    class KlingelballUI: public Ui_KlingelballUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KLINGELBALLUI_H
