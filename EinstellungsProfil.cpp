/**********************************************/
//Filename: EinstellungsProfil.cpp
//Author: Samuel Zeillinger
//Created On: 13 November 2023 20:16
//Description: EinstellungsProfil class implementation
//Not used in this version of the project (V1.0)
/**********************************************/

#include "EinstellungsProfil.h"



EinstellungsProfil::EinstellungsProfil(){
    this->Profil_Name = "Profil";
    this->Volume = 0;
    this->Frequenz_Bewegend = 0;
    this->Frequenz_Stillstehend = 0;
}

EinstellungsProfil::EinstellungsProfil(const EinstellungsProfil &other){
   this->Profil_Name = other.Profil_Name;
   this->Volume = other.Volume;
   this->Frequenz_Stillstehend = other.Frequenz_Stillstehend;
   this->Frequenz_Bewegend = other.Frequenz_Bewegend;
}

EinstellungsProfil::EinstellungsProfil(QString name, int Volume, int Frequenz_Stillstehend, int Frequenz_Bewegend)
    : QGroupBox(){

    this->Profil_Name = name;
    this->Volume = Volume;
    this->Frequenz_Stillstehend = Frequenz_Stillstehend;
    this->Frequenz_Bewegend = Frequenz_Bewegend;

    QVBoxLayout *vLayout = new QVBoxLayout(this);

    profil_name_label = new QLabel(this);
    profil_Volume_label = new QLabel(this);
    profil_Frequenz_Stillstehend_label = new QLabel(this);
    profil_Frequenz_Bewegend_label = new QLabel(this);

    profil_name_label->setText(getName());
    profil_Volume_label->setText("Volume: " + QString::number(getVolume()) + "%");
    profil_Frequenz_Stillstehend_label->setText("Frequenz-Stillstehend: " + QString::number(getFrequenz_Stillstehend()) + "%");
    profil_Frequenz_Bewegend_label->setText("Frequenz-Bewegend: " + QString::number(getFrequenz_Bewegend()) + "%");

    //profil_name_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    //profil_Volume_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    //profil_Frequenz_Stillstehend_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    //profil_Frequenz_Bewegend_label->setTextInteractionFlags(Qt::TextSelectableByMouse);

    profil_Volume_label->setAccessibleDescription(getName());
    profil_Frequenz_Stillstehend_label->setAccessibleDescription(getName());
    profil_Frequenz_Bewegend_label->setAccessibleDescription(getName());


    profil_Volume_label->setAccessibleName(profil_Volume_label->text());
    profil_Frequenz_Stillstehend_label->setAccessibleName(profil_Frequenz_Stillstehend_label->text());
    profil_Frequenz_Bewegend_label->setAccessibleName(profil_Frequenz_Bewegend_label->text());

    this->setAccessibleName (getName()+
                                   profil_Volume_label->accessibleName()+
                                   profil_Frequenz_Bewegend_label->accessibleName()+
                                   profil_Frequenz_Stillstehend_label->accessibleName());


    vLayout->addWidget(profil_name_label);
    vLayout->addWidget(profil_Volume_label);
    vLayout->addWidget(profil_Frequenz_Bewegend_label);
    vLayout->addWidget(profil_Frequenz_Stillstehend_label);

    this->setLayout(vLayout);

    this->setCheckable(true);
    this->setChecked(false);



    profil_name_label->setStyleSheet(groupBox_namelabel_stylesheet);
    profil_Volume_label->setStyleSheet(groupBox_namelabel_stylesheet);
    profil_Frequenz_Bewegend_label->setStyleSheet(groupBox_label_stylesheet);
    profil_Frequenz_Stillstehend_label->setStyleSheet(groupBox_label_stylesheet);

    QFont Profil_title_Font("Segoe UI", 20, QFont::Bold);
    QFont Profil_text_Font("Segoe UI", 15);

    this->setFixedHeight(Profil_title_Font.pointSize()+ (3*Profil_text_Font.pointSize())+60);
    //Font cuts in the bottom

    profil_name_label->setFont(Profil_title_Font);
    profil_Volume_label->setFont(Profil_text_Font);
    profil_Frequenz_Bewegend_label->setFont(Profil_text_Font);
    profil_Frequenz_Stillstehend_label->setFont(Profil_text_Font);

    //TODO: deselect when new profile is selected
    //TODO: Einstellungen zu profil

}

void EinstellungsProfil::toggle_profile(){
    if (this->isChecked()){
        this->setChecked(false);
        setLabelStylesheet(&groupBox_namelabel_stylesheet);
    }else if(!this->isChecked()){
        this->setChecked(true);
        setLabelStylesheet(&groupBox_namelabel_stylesheet_black);
    }

}

void EinstellungsProfil::mousePressEvent(QMouseEvent *event){
    Q_UNUSED(event);
    if (this->isChecked()){
        this->toggle_profile();
        emit profile_selection_updated();
    }else{
        emit profile_selected();
        this->toggle_profile();
        emit profile_selection_updated();
    }
}

void EinstellungsProfil::setLabelStylesheet(QString *stylesheet){
    profil_name_label->setStyleSheet(*stylesheet);
    profil_Volume_label->setStyleSheet(*stylesheet);
    profil_Frequenz_Bewegend_label->setStyleSheet(*stylesheet);
    profil_Frequenz_Stillstehend_label->setStyleSheet(*stylesheet);

}

