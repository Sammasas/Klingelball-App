QT       += core gui
QT       += multimedia
QT       += bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_ICONS = Logo_v2.ico


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
    android/AndroidManifest.xml \
    android/build.gradle \
    android/res/values/libs.xml

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
