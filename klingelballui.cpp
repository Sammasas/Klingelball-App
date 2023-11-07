#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    SetupUI();



}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}



