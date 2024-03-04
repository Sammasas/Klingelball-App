/**********************************************/
//Filename: iOSSettings.h
//Author: Samuel Zeillinger
//Created On: 14 February 2024 19:31
//Description: class to include objective-c code (.mm file) in cpp project. Used to access iOS systemsettings
/**********************************************/

#ifndef IOSSETTINGS_H
#define IOSSETTINGS_H

class iOSSettings {
public:
    static int getPrefferedFont();
};


#endif // IOSSETTINGS_H
