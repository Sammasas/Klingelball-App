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
    qDebug() << "main enter";
    QApplication a(argc, argv);
    qDebug() << "main app";
    KlingelballUI w;
    qDebug() << "main init";
    w.show();
    qDebug() << "main show";

    w.setAccessibleName("  ");

    return a.exec();
}
