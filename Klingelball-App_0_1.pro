QT       += core gui
QT       += multimedia
QT       += bluetooth


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_ICONS = KlingelballIcon1024.png
ICON = KlingelballIcon1024.png

TRANSLATIONS += Klingelball_App_0_1_en_001.ts \
    Klingelball_App_0_1_pl_PL.ts



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EinstellungsProfil.cpp \
    Klingelball-BLE-Functions.cpp \
    Klingelball-UI-Functions.cpp \
    Klingelball-UI-SetupFunctions.cpp \
    deviceinfo.cpp \
    main.cpp \
    klingelballui.cpp


HEADERS += \
    EinstellungsProfil.h \
    deviceinfo.h \
    klingelballui.h

FORMS += \
    klingelballui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    UI-Resources.qrc

DISTFILES += \
    Assets.xcassets \
    Assets.xcassets/AppIcon.appiconset/Contents.json \
    Assets.xcassets/AppIcon.appiconset/KlingelballIcon1024.png \
    Assets.xcassets/Contents.json \
    Info.plist \
    android/AndroidManifest.xml \
    android/AndroidSettings.java \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-xhdpi/icon.png \
    android/res/drawable-xxhdpi/icon.png \
    android/res/drawable-xxxhdpi/icon.png \
    android/res/values/libs.xml \
    android/res/xml/qtprovider_paths.xml \
    android/src/Klingelball/AndroidSettings.java

contains(ANDROID_TARGET_ARCH,x86_64) {
    ANDROID_PACKAGE_SOURCE_DIR = \
          $$PWD/android-sources

}

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android

}

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android

}

android{
ANDROID_PACKAGE_SOURCE_DIR = \
    $$PWD/android
    OTHER_FILES += android/src/Klingelball
}

ios{
    QMAKE_INFO_PLIST = Info.plist
    HEADERS += iOSSettings.h
    OBJECTIVE_SOURCES += iOSSettings.mm
    QMAKE_ASSET_CATALOGS = $$PWD/Assets.xcassets
    QMAKE_ASSET_CATALOGS_APP_ICON = "AppIcon"
}
