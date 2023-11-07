#ifndef EINSTELLUNGSPROFIL_H
#define EINSTELLUNGSPROFIL_H
#include <QWidget>

class EinstellungsProfil : QWidget{

private:
    QString Profil_Name;
    int Volume = 0;
    int Frequenz_Stillstehend = 0;
    int Frequenz_Bewegend = 0;
public:
    EinstellungsProfil(QString name, int Volume, int Frequenz_Stillstehend, int Frequenz_Bewegend);
    QString getName(){return this->Profil_Name;}
    int getVolume(){return this->Volume;}
    int getFrequenz_Stillstehend(){return this->Frequenz_Stillstehend;}
    int getFrequenz_Bewegend(){return this->Frequenz_Bewegend;}

};

#endif // EINSTELLUNGSPROFIL_H
