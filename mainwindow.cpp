#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMediaPlaylist>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->hide();
    vid=new QVideoWidget(this);
    player=new QMediaPlayer(this);
    playlist=new QMediaPlaylist(this);
    player->setPlaylist(playlist);
    ui->gridLayout->addWidget(vid);
    player->setVideoOutput(vid);
    player->setVolume(70);
    ui->pushButton->hide();
    ui->verticalSlider->setRange(0,100);
    ui->verticalSlider->setValue(player->volume());
    ui->horizontalSlider->setRange(0,player->duration()/1000);
    connect(player, SIGNAL(durationChanged(qint64)), SLOT(durationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), SLOT(positionChanged(qint64)));
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)), SLOT(seek(int)));
    connect(ui->verticalSlider,SIGNAL(sliderMoved(int)),player,SLOT(setVolume(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLocal_File_triggered()
{
    QString fname;
    fname=QFileDialog::getOpenFileName(this,tr("Open"));
    player->setMedia(QUrl::fromLocalFile(fname));
    player->play();

}

void MainWindow::on_actionStream_triggered()
{
    ui->lineEdit->show();

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionPlay_triggered()
{
    ui->lineEdit->hide();
    player->play();
}

void MainWindow::on_actionPause_triggered()
{
    if(player->PlayingState)
        player->pause();
    else
        player->play();
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
}

void MainWindow::on_actionFull_Screen_triggered()
{
    if(vid->isFullScreen()==true){

        vid->setFullScreen(false);
        ui->gridLayout->addWidget(vid);
    }
    else
        vid->setFullScreen(true);
}

void MainWindow::positionChanged(qint64 progress)
{
    if(!ui->horizontalSlider->isSliderDown())
        ui->horizontalSlider->setValue(progress / 1000);
}

void MainWindow::durationChanged(qint64 duration)
{
    ui->horizontalSlider->setMaximum(duration /1000);
}

void MainWindow::seek(int secs)
{
    player->setPosition(secs*1000);
}

void MainWindow::on_pushButton_clicked()
{
    QUrl url;
    url=ui->lineEdit->text();
    player->setMedia(url);
    ui->lineEdit->hide();
    ui->pushButton->hide();
}
