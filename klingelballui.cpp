#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    Profile_list = new QList<EinstellungsProfil *>;
    SetupUI();

    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );



}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}




void KlingelballUI::on_FontSize_spinBox_valueChanged(int arg1)
{

}











