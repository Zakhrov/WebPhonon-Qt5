#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings defaultSettings;
        if(!defaultSettings.contains("server"))
        {
        defaultSettings.setValue("server","localhost");
        defaultSettings.setValue("username","root");
        defaultSettings.setValue("password","root");
        defaultSettings.setValue("database","webphonon");
        defaultSettings.setValue("dbtype","QMYSQL");
        defaultSettings.sync();
        }
    QSplashScreen splash;
    QPixmap pix;
    pix.load(":/splash/WebPhonon-Master-text2.png");
    splash.setPixmap(pix);
    splash.show();
    MainWindow w;
    if(argc>1)
    w.cmdopen(argv[1]);
    w.showMaximized();
    return a.exec();
}
