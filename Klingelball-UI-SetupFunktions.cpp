#include "klingelballui.h"
#include "ui_klingelballui.h"


void KlingelballUI::setup_UI(){

    setup_font();
    setup_labels();
    setup_buttons();
    setup_spinbox();
    setup_lineedit();

}


void KlingelballUI::setup_lineedit()
{
    ui->new_profile_lineEdit->setFont(*dynamicSizeFont);
}


void KlingelballUI::setup_spinbox()
{
    ui->Volume->setFont(*dynamicSizeFont);
    ui->Bis_Frequ->setFont(*dynamicSizeFont);
    ui->Von_Frequ->setFont(*dynamicSizeFont);
}

void KlingelballUI::setup_font(){
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

    dynamicSizeFont = new QFont("Segoe UI", ui->Volume_UP->height()*0.5, QFont::Bold);

}


void KlingelballUI::setup_buttons()
{
    ui->Volume_UP->setIconSize(QSize(ui->Volume_UP->height()*0.7, ui->Volume_UP->height()));
    ui->Volume_Down->setIconSize(QSize(ui->Volume_UP->height()*0.7, ui->Volume_UP->height()));

    ui->Bis_Frequ_Up->setIconSize(QSize(ui->Volume_UP->height()*0.7, ui->Volume_UP->height()));
    ui->Bis_Frequ_Down->setIconSize(QSize(ui->Volume_UP->height()*0.7, ui->Volume_UP->height()));

    ui->Von_Frequ_Up->setIconSize(QSize(ui->Volume_UP->height()*0.7, ui->Volume_UP->height()));
    ui->Von_Frequ_Down->setIconSize(QSize(ui->Volume_UP->height()*0.7, ui->Volume_UP->height()));

    ui->tabWidget->setIconSize(QSize(ui->Volume_UP->height()*0.5, ui->Volume_UP->height()*0.5));

    ui->new_profile_button->setFont(*dynamicSizeFont);
    ui->new_profile_cancle_button->setFont(*dynamicSizeFont);

}


void KlingelballUI::setup_labels()
{
    ui->Volume_Label->setFont(*dynamicSizeFont);
    ui->Frequenz_Label->setFont(*dynamicSizeFont);
    ui->Bis_Frequenz_Label->setFont(*dynamicSizeFont);
    ui->Von_Frequenz_Label->setFont(*dynamicSizeFont);

    ui->new_profile_label->setFont(*dynamicSizeFont);
    ui->new_profile_volume_label->setFont(*dynamicSizeFont);
    ui->new_profile_Bew_Freq_label->setFont(*dynamicSizeFont);
    ui->new_profile_Still_Freq_label->setFont(*dynamicSizeFont);

    ui->Volume_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Frequenz_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Von_Frequenz_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Bis_Frequenz_Label->setTextInteractionFlags(Qt::TextSelectableByMouse );
    ui->Aussehen_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
}
