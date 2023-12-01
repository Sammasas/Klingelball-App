#include "klingelballui.h"

#include <QApplication>
#include <QFile>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KlingelballUI w;
    w.show();

    QFile styleSheetFile(":/stylesheet/lightmode.css");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    QFontDatabase::addApplicationFont(":/Font/InterVariable.ttf");
    QFont interVariable("Inter Variable Text", 10, QFont::Bold);
    w.setFont(interVariable);
    w.setStyleSheet(styleSheet);


    return a.exec();
}
