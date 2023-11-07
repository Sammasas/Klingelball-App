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

    EinstellungsProfil *testprofil = new EinstellungsProfil("test1", 50, 20, 30);
    EinstellungsProfil *testprofil1 = new EinstellungsProfil("test2", 50, 20, 30);
    EinstellungsProfil *testprofil2 = new EinstellungsProfil("test3", 50, 20, 30);
    EinstellungsProfil *testprofil3 = new EinstellungsProfil("test4", 50, 20, 30);
     EinstellungsProfil *testprofil4 = new EinstellungsProfil("test5", 50, 20, 30);
      EinstellungsProfil *testprofil5 = new EinstellungsProfil("test6", 50, 20, 30);
       EinstellungsProfil *testprofil6 = new EinstellungsProfil("test7", 50, 20, 30);
        EinstellungsProfil *testprofil7 = new EinstellungsProfil("test8", 50, 20, 30);
         EinstellungsProfil *testprofil8 = new EinstellungsProfil("test9", 50, 20, 30);
          EinstellungsProfil *testprofil9 = new EinstellungsProfil("test10", 50, 20, 30);


    createUIProfile(testprofil);
    createUIProfile(testprofil1);
    createUIProfile(testprofil2);
    createUIProfile(testprofil3);
    createUIProfile(testprofil4);
    createUIProfile(testprofil5);
    createUIProfile(testprofil6);
    createUIProfile(testprofil7);


}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}



