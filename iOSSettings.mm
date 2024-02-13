#include "iOSSettings.h"
#include <UIKit/UIKit.h>


int iOSSettings::getPrefferedFont() {
    return [UIFont preferredFontForTextStyle:UIFontTextStyleBody].pointSize;
}

