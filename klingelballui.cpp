#include "klingelballui.h"
#include "ui_klingelballui.h"

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

