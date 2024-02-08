package Klingelball;

import android.content.Context;
import android.content.res.Configuration;
import android.util.DisplayMetrics;
import android.view.WindowManager;

public class AndroidSettings {
    public static float getFontScale(Context context) {
        //return getResources().getConfiguration().fontScale;
        Configuration configuration = context.getResources().getConfiguration();

                // Get the font scale from the configuration
                float fontScale = configuration.fontScale;

                return fontScale;
    }
}
