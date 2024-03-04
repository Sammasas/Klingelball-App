/**********************************************/
//Filename: EinstellungsProfil.h
//Author: Samuel Zeillinger
//Created On: 13 November 2023 18:44
//Description: deviceinfo class implementation
//Not used in this version of the project (V1.0)
/**********************************************/

#ifndef EINSTELLUNGSPROFIL_H
#define EINSTELLUNGSPROFIL_H
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QFrame>
#include <QGroupBox>
#include <QSpacerItem>
#include <QMouseEvent>
#include <QFont>

class KlingelballUI;

class EinstellungsProfil : public QGroupBox{
 Q_OBJECT

private:
    QString Profil_Name;
    int Volume = 0;
    int Frequenz_Stillstehend = 0;
    int Frequenz_Bewegend = 0;

    QLabel *profil_name_label;
    QLabel *profil_Volume_label;
    QLabel *profil_Frequenz_Stillstehend_label;
    QLabel *profil_Frequenz_Bewegend_label;

    QString groupBox_namelabel_stylesheet = "QLabel{color: white;"
                                            "font-weight: bold;}";


    QString groupBox_label_stylesheet = "QLabel{color: white;}";
    QString groupBox_namelabel_stylesheet_black = "QLabel{color: black;}";
public:
    EinstellungsProfil();
    EinstellungsProfil(const EinstellungsProfil &other);
    EinstellungsProfil(QString name, int Volume, int Frequenz_Stillstehend, int Frequenz_Bewegend);

    EinstellungsProfil &operator=(const EinstellungsProfil &other);

    [[nodiscard]] inline QString getName()              { return this->Profil_Name; }
    [[nodiscard]] inline int getVolume()                { return this->Volume; }
    [[nodiscard]] inline int getFrequenz_Stillstehend() { return this->Frequenz_Stillstehend; }
    [[nodiscard]] inline int getFrequenz_Bewegend()     { return this->Frequenz_Bewegend; }

    inline void setName(QString name)                   { this->Profil_Name = name; }
    inline void setVolume(int Volume)                   { this->Volume = Volume; }
    inline void setFrequenz_Stillstehend(int freq)      { this->Frequenz_Stillstehend = freq; }
    inline void setFrequenz_Bewegend(int freq)          { this->Frequenz_Bewegend = freq; }

    void toggle_profile();
    void setLabelStylesheet(QString *stylesheet);


protected:
    void mousePressEvent(QMouseEvent * event);

Q_SIGNALS:
    void profile_selected();
    void profile_selection_updated();
};


#endif // EINSTELLUNGSPROFIL_H
