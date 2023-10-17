#include "klingelballui.h"
#include "ui_klingelballui.h"
#include "QSize"

KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);


}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}


void KlingelballUI::on_Bis_Frequ_valueChanged(int arg1)
{

}

