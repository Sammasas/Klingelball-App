/**********************************************/
//Filename: iOSSettings.mm
//Author: Samuel Zeillinger
//Created On: 14 February 2024 9:31
//Description: iOSSettings class implementation
//Note: This code was partially written with ChatGPT
/**********************************************/
#include "iOSSettings.h"
#include <UIKit/UIKit.h>


int iOSSettings::getPrefferedFont() {
    return [UIFont preferredFontForTextStyle:UIFontTextStyleBody].pointSize;
}

