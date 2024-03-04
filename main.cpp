/**********************************************/
//Filename: main.cpp
//Author: Samuel Zeillinger
//Created On: 30 September ‎2023 ‏‎20:01
//Description: Main application
/**********************************************/

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
        w.setStyleSheet(styleSheet);
    }else{
        QFile styleSheetFile(":/stylesheet/lightmode.css");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        w.setStyleSheet(styleSheet);
    }


    return a.exec();
}
