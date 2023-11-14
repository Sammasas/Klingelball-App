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
    this->setMinimumHeight(120);

    this->setCheckable(true);
    this->setChecked(false);

    QString groupBox_namelabel_stylesheet = "QLabel{color: black;"
                                            "font-weight: bold;}";


    QString groupBox_label_stylesheet = "QLabel{color: black;}";

    profil_name_label->setStyleSheet(groupBox_namelabel_stylesheet);
    profil_Volume_label->setStyleSheet(groupBox_label_stylesheet);
    profil_Frequenz_Bewegend_label->setStyleSheet(groupBox_label_stylesheet);
    profil_Frequenz_Stillstehend_label->setStyleSheet(groupBox_label_stylesheet);

    QFont Profil_title_Font("Segoe UI", 20, QFont::Bold);
    QFont Profil_text_Font("Segoe UI", 15);

    this->setMinimumHeight(Profil_title_Font.pointSize()+ (3*Profil_text_Font.pointSize())+40);

    profil_name_label->setFont(Profil_title_Font);
    profil_Volume_label->setFont(Profil_text_Font);
    profil_Frequenz_Bewegend_label->setFont(Profil_text_Font);
    profil_Frequenz_Stillstehend_label->setFont(Profil_text_Font);
    //TODO: deselect when new profile is selected
    //TODO: Einstellungen zu profil

}

void EinstellungsProfil::profile_selected(){
    if (this->isChecked()){
        this->setChecked(false);
    }else if(!this->isChecked())
        this->setChecked(true);

}

void EinstellungsProfil::mousePressEvent(QMouseEvent *event){
    this->profile_selected();
}
