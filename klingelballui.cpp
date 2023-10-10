#include "klingelballui.h"
#include "ui_klingelballui.h"

KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);
    //Hello
    ui->label_2->setText("Test");
}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}

