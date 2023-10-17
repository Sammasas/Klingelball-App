#include "klingelballui.h"
#include "ui_klingelballui.h"


void KlingelballUI::SetupUI(){
    /******Buttons*********/
    ui->Volume_UP->setIconSize(QSize(ui->Volume_UP->height(), ui->Volume_UP->height()));
    ui->Volume_Down->setIconSize(QSize(ui->Volume_UP->height(), ui->Volume_UP->height()));

    ui->Bis_Frequ_Up->setIconSize(QSize(ui->Volume_UP->height(), ui->Volume_UP->height()));
    ui->Bis_Frequ_Down->setIconSize(QSize(ui->Volume_UP->height(), ui->Volume_UP->height()));

    ui->Von_Frequ_Up->setIconSize(QSize(ui->Volume_UP->height(), ui->Volume_UP->height()));
    ui->Von_Frequ_Down->setIconSize(QSize(ui->Volume_UP->height(), ui->Volume_UP->height()));

    /*****Font************/
    qreal refDpi = 444.;
    qreal refHeight = 2340.;
    qreal refWidth = 1080.;

    QRect rect = KlingelballUI::geometry();

    qreal height = qMax(rect.width(), rect.height());
    qreal width = qMin(rect.width(), rect.height());

    qreal dpi = KlingelballUI::logicalDpiX();
    qreal m_ratio = qMin(height/refHeight, width/refWidth);
    qreal m_ratioFont = qMin(height*refDpi/(dpi*refHeight), width*refDpi/(dpi*refWidth));

    QFont serifFont("Times", 16*m_ratioFont, QFont::Bold);
    /*
    ui->Bis_Frequenz_Label->setFont(serifFont);
    ui->Frequenz_Label->setFont(serifFont);
    ui->Von_Frequenz_Label->setFont(serifFont);
    ui->Volume_Label->setFont(serifFont);*/


    //**********Layout*****************//


    /***********SpinBox*****************/
    ui->Bis_Frequ->setFocusPolicy(Qt::NoFocus);

}
