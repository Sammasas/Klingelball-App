#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);
    setup_UI();
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    Profile_list = new QList<EinstellungsProfil *>;


    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );

    setupBLE();
    //ui->connectKlingelball->setDisabled(true);
}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}





















