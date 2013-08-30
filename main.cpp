#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSplashScreen splash;
    QPixmap pix;
    pix.load(":/Splash/WebPhonon-Master-text2.png");
    splash.setPixmap(pix);
    splash.show();
    w.showMaximized();
    //QThread::sleep(5);
    splash.finish(&w);
    return a.exec();
}
