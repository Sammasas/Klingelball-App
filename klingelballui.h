#ifndef KLINGELBALLUI_H
#define KLINGELBALLUI_H

#include <QMainWindow>
#include <QSoundEffect>
#include "QSize"
#include <QByteArray>
#include <QBuffer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QFile>
#include "EinstellungsProfil.h"
#include <QScroller>
#include <QTimer>
#include <QList>


QT_BEGIN_NAMESPACE
namespace Ui { class KlingelballUI; }
QT_END_NAMESPACE

class KlingelballUI : public QMainWindow
{
    Q_OBJECT

public:
    KlingelballUI(QWidget *parent = nullptr);
    ~KlingelballUI();

public slots:
    void change_profile_selection();

private slots:
    void on_Bis_Frequ_valueChanged(int arg1);

    void on_Volume_valueChanged(int arg1);

    void on_Lightmode_checkBox_clicked();

    void on_Darkmode_checkBox_clicked();


    void on_FontSize_spinBox_valueChanged(int arg1);

    void on_profil_from_currentsettings_button_clicked();

    void on_new_profile_button_clicked();

private:
    Ui::KlingelballUI *ui;

    QSoundEffect effect;

    void playSoundEffect(int Volume);
    void SetupUI();

    void createUIProfile(EinstellungsProfil *profil);

    QList<EinstellungsProfil *> *Profile_list;


};
#endif // KLINGELBALLUI_H
