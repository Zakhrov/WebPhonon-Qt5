#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <KDE/Phonon/VideoWidget>
#include <KDE/Phonon/MediaObject>
#include <KDE/Phonon/MediaSource>
#include <KDE/Phonon/AudioOutput>
#include <QMainWindow>
#include <QTableWidgetItem>
#include "dropwidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     void cmdopen(QString cmdfile);
    ~MainWindow();
public slots:
     void dropdata(const QMimeData *mimeData);
private slots:
    void on_actionLocal_File_triggered();

    void on_actionStream_triggered();

    void on_actionExit_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionFull_Screen_triggered();

//    void positionChanged(qint64);

//    void durationChanged(qint64);

//    void seek(int);
    void next();

    void widgetpause(QKeyEvent *event);

    void on_pushButton_clicked();

    void on_actionBack_triggered();

    void on_actionFoward_triggered();

    void on_actionShow_Playlist_triggered();

    void on_actionVolume_Up_triggered();

    void on_actionVolume_Down_triggered();

    void on_actionSkip_Foward_triggered();

    void on_actionSkip_Backward_triggered();

    void on_actionClear_Playlist_triggered();

    void on_actionAuto_triggered();

    void on_actionSquare_triggered();

    void on_actionWideScreen_triggered();
    void timechanged(qint64);
    void totalTimeChanged(qint64);

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    DropWidget *vid;
    Phonon::AudioOutput *sndout;
        QList<Phonon::MediaSource> sources;
        QTableWidgetItem *item;
        qreal volume;
        QStringList collabel;


};

#endif // MAINWINDOW_H
