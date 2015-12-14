#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QCommandLineParser>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("WebPhonon-Qt5");
    QApplication::setApplicationVersion("1.7.0");
    QCommandLineParser parser;
    parser.addPositionalArgument("url","Open URL");
    parser.process(a);
    const QStringList args=parser.positionalArguments();
    QSplashScreen splash;
    QPixmap pix;
    pix.load(":/Splash/WebPhonon-Master-text2.png");
    splash.setPixmap(pix);
    splash.show();
    MainWindow w;
    if(!args.empty())
    {
        w.cmdopen(args.at(0));
    }
        w.showMaximized();

    return a.exec();
}
