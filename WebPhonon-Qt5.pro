#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T17:50:15
#
#-------------------------------------------------

QT       += core gui phonon4qt5 #multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebPhonon-Qt5
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    dropwidget.cpp

HEADERS  += mainwindow.h \
    dropwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    Icons.qrc

OTHER_FILES += \
    video-television.png \
    media-playback-stop.png \
    media-playback-start.png \
    media-playback-pause.png \
    application-exit.png \
    document-open.png \
    applications-internet.png \
    WebPhonon-Master-text2.png \
    icons/16x16/WebPhononIcon.png \
    icons/32x32/WebPhononIcon.png \
    icons/48x48/WebPhononIcon.png \
    icons/64x64/WebPhononIcon.png \
    icons/128x128/WebPhononIcon.png \
    icons/256x256/WebPhononIcon.png \
    icons/512x512/WebPhononIcon.png \
    WebPhonon-Qt5.desktop

    target.path = /usr/bin
    desktop.path= /usr/share/applications
    desktop.files += WebPhonon.desktop
    icon16.path= /usr/share/icons/hicolor/16x16/apps
    icon32.path= /usr/share/icons/hicolor/32x32/apps
    icon48.path= /usr/share/icons/hicolor/48x48/apps
    icon64.path= /usr/share/icons/hicolor/64x64/apps
    icon128.path= /usr/share/icons/hicolor/128x128/apps
    icon256.path= /usr/share/icons/hicolor/256x256/apps
    icon512.path= /usr/share/icons/hicolor/512x512/apps

    icon16.files +=    icons/16x16/WebPhononIcon.png
    icon32.files +=    icons/32x32/WebPhononIcon.png
    icon48.files +=    icons/48x48/WebPhononIcon.png
    icon64.files +=    icons/64x64/WebPhononIcon.png
    icon128.files +=    icons/128x128/WebPhononIcon.png
    icon256.files +=    icons/256x256/WebPhononIcon.png
    icon512.files +=    icons/512x512/WebPhononIcon.png

INSTALLS += target icon16 icon32 icon48 icon64 icon128 icon256 icon512 desktop
