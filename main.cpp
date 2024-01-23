#include "klingelballui.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KlingelballUI w;
    w.show();

    if(QGuiApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark){
        QFile styleSheetFile(":/stylesheet/darkmode.css");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        QFont interVariable("Inter Variable Text", 10, QFont::Bold);
        w.setStyleSheet(styleSheet);
    }else{
        QFile styleSheetFile(":/stylesheet/lightmode.css");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        w.setStyleSheet(styleSheet);
    }


    return a.exec();
}
