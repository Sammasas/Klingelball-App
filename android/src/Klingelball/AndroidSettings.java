/**********************************************/
//Filename: AndroidSettings.java
//Author: Samuel Zeillinger
//Created On: 7 February 2024 21:13
//Description: Java class to access android system settings
//Note: This code was partially written with ChatGPT
/**********************************************/

package Klingelball;

import android.content.Context;
import android.content.res.Configuration;
import android.util.DisplayMetrics;
import android.view.WindowManager;

public class AndroidSettings {
    public static float getFontScale(Context context) {
        Configuration configuration = context.getResources().getConfiguration();

                // Get the font scale from configuration
                float fontScale = configuration.fontScale;

                return fontScale;
    }
}
