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

private:
    Ui::KlingelballUI *ui;
};
#endif // KLINGELBALLUI_H
