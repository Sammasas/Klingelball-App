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



QT_BEGIN_NAMESPACE
namespace Ui { class KlingelballUI; }
QT_END_NAMESPACE

class KlingelballUI : public QMainWindow
{
    Q_OBJECT

public:
    KlingelballUI(QWidget *parent = nullptr);
    ~KlingelballUI();

private slots:
    void on_Bis_Frequ_valueChanged(int arg1);

    void on_Volume_valueChanged(int arg1);

    void on_Lightmode_checkBox_clicked();

    void on_Darkmode_checkBox_clicked();

private:
    Ui::KlingelballUI *ui;

    QSoundEffect effect;
    void playSoundEffect(int Volume);

    void SetupUI();
};
#endif // KLINGELBALLUI_H
