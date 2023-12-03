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
    setup_UI();

    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture );

    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(15000);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &KlingelballUI::addDevice);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &KlingelballUI::ScanError);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &KlingelballUI::ScanFinished);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
            this, &KlingelballUI::ScanFinished);




}

KlingelballUI::~KlingelballUI()
{
    delete ui;
}




void KlingelballUI::on_FontSize_spinBox_valueChanged(int arg1)
{

}











