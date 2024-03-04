/**********************************************/
//Filename: iOSSettings.mm
//Author: Samuel Zeillinger
//Created On: 14 February 2024 9:31
//Description: iOSSettings class implementation
/**********************************************/
#include "iOSSettings.h"
#include <UIKit/UIKit.h>


int iOSSettings::getPrefferedFont() {
    return [UIFont preferredFontForTextStyle:UIFontTextStyleBody].pointSize;
}

