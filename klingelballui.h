#ifndef KLINGELBALLUI_H
#define KLINGELBALLUI_H

#include <QMainWindow>

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

private:
    Ui::KlingelballUI *ui;

    void SetupUI();
};
#endif // KLINGELBALLUI_H
