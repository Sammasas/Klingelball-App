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

    w.setAccessibleName("  ");

    return a.exec();
}
