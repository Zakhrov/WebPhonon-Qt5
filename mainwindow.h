#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMediaContent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *vid;
    QMediaPlaylist *playlist;
        QList<QMediaContent> urls;
        QTableWidgetItem *item;

};

#endif // MAINWINDOW_H
