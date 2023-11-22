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

    EinstellungsProfil *test_profil1 = new EinstellungsProfil("Turnsaal", 70, 20, 80);
    EinstellungsProfil *test_profil2 = new EinstellungsProfil("Sportplatz", 70, 20, 80);
    create_Profile_visualisation(test_profil1);
    create_Profile_visualisation(test_profil2);



}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}




void KlingelballUI::on_FontSize_spinBox_valueChanged(int arg1)
{

}











