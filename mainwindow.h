#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMediaContent>
#include "dropwidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
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

    void positionChanged(qint64);

    void durationChanged(qint64);

    void seek(int);

    void widgetpause(QKeyEvent *event);

    void on_pushButton_clicked();

    void on_actionBack_triggered();

    void on_actionFoward_triggered();

    void on_actionShow_Playlist_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    DropWidget *vid;
    QMediaPlaylist *playlist;
        QList<QMediaContent> urls;
        QTableWidgetItem *item;

};

#endif // MAINWINDOW_H
