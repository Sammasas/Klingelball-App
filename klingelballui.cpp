#include "klingelballui.h"
#include "ui_klingelballui.h"


KlingelballUI::KlingelballUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KlingelballUI)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    SetupUI();

    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );


    EinstellungsProfil *testprofil = new EinstellungsProfil("Turnsaal", 80, 10, 50);
    EinstellungsProfil *testprofil1 = new EinstellungsProfil("test2", 50, 20, 30);
    EinstellungsProfil *testprofil2 = new EinstellungsProfil("test3", 50, 20, 30);



    createUIProfile(testprofil);
    createUIProfile(testprofil1);
    createUIProfile(testprofil2);


    //ui->tabWidget->setTabEnabled(1, false);

}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}




void KlingelballUI::on_FontSize_spinBox_valueChanged(int arg1)
{

}

