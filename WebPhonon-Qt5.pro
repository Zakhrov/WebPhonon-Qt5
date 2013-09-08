#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T17:50:15
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebPhonon-Qt5
TEMPLATE = app
target.path=/usr/bin
INSTALLS +=target


SOURCES += main.cpp\
        mainwindow.cpp \

HEADERS  += mainwindow.h \

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
    WebPhonon-Master-text2.png
