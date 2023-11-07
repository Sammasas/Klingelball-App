#include "EinstellungsProfil.h"


EinstellungsProfil::EinstellungsProfil(QString name, int Volume, int Frequenz_Stillstehend, int Frequenz_Bewegend)
    : QGroupBox(){

    this->Profil_Name = name;
    this->Volume = Volume;
    this->Frequenz_Stillstehend = Frequenz_Stillstehend;
    this->Frequenz_Bewegend = Frequenz_Bewegend;

    QVBoxLayout *vLayout = new QVBoxLayout(this);

    QLabel *profil_name_label = new QLabel(this);
    QLabel *profil_Volume_label = new QLabel(this);
    QLabel *profil_Frequenz_Stillstehend_label = new QLabel(this);
    QLabel *profil_Frequenz_Bewegend_label = new QLabel(this);

    profil_name_label->setText(getName());
    profil_Volume_label->setText("Volume: " + QString::number(getVolume()) + "%");
    profil_Frequenz_Stillstehend_label->setText("Frequenz-Stillstehend: " + QString::number(getFrequenz_Stillstehend()) + "%");
    profil_Frequenz_Bewegend_label->setText("Frequenz-Bewegend: " + QString::number(getFrequenz_Bewegend()) + "%");

    profil_name_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    profil_Volume_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    profil_Frequenz_Stillstehend_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    profil_Frequenz_Bewegend_label->setTextInteractionFlags(Qt::TextSelectableByMouse);

    profil_Volume_label->setAccessibleDescription(getName());
    profil_Frequenz_Stillstehend_label->setAccessibleDescription(getName());
    profil_Frequenz_Bewegend_label->setAccessibleDescription(getName());

    profil_Volume_label->setAccessibleName(getName()+profil_Volume_label->text());
    profil_Frequenz_Stillstehend_label->setAccessibleName(getName()+profil_Frequenz_Stillstehend_label->text());
    profil_Frequenz_Bewegend_label->setAccessibleName(getName()+profil_Frequenz_Bewegend_label->text());

    vLayout->addWidget(profil_name_label);
    vLayout->addWidget(profil_Volume_label);
    vLayout->addWidget(profil_Frequenz_Bewegend_label);
    vLayout->addWidget(profil_Frequenz_Stillstehend_label);

    this->setLayout(vLayout);

    this->setMinimumHeight(120);

}
