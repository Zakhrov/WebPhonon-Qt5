#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splash;
    QPixmap pix;
    pix.load(":/Splash/WebPhonon-Master-text2.png");
    splash.setPixmap(pix);
    splash.show();
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
