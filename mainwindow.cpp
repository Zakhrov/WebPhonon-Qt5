#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMediaPlaylist>
#include "dropwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->hide();
    vid=new DropWidget(this);
    vid->setVisible(true);
    vid->setBaseSize(1024,400);
    vid->setAutoFillBackground(true);
    ui->tableWidget->setVisible(false);
    player=new QMediaPlayer(this);
    playlist=new QMediaPlaylist(this);
    player->setPlaylist(playlist);
    ui->gridLayout->addWidget(vid);
    player->setVideoOutput(vid);
    player->setVolume(30);
    ui->pushButton->hide();
    ui->verticalSlider->setRange(0,100);
    ui->verticalSlider->setValue(player->volume());
    ui->horizontalSlider->setRange(0,player->duration()/1000);
    connect(player, SIGNAL(durationChanged(qint64)), SLOT(durationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), SLOT(positionChanged(qint64)));
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)), SLOT(seek(int)));
    connect(ui->verticalSlider,SIGNAL(sliderMoved(int)),player,SLOT(setVolume(int)));
    connect(vid,SIGNAL(geturls(const QMimeData*)),this,SLOT(dropdata(const QMimeData*)));
    connect(vid,SIGNAL(capturespace(QKeyEvent*)),this,SLOT(widgetpause(QKeyEvent*)));
    ui->tableWidget->setColumnCount(1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dropdata(const QMimeData *mimeData)
{

    //activates drag n drop
    int i;
    int index=urls.size();
    if (mimeData->hasUrls()) {
             foreach (QUrl url, mimeData->urls()) {
                 urls.append(url);
                QTableWidgetItem *uitem=new QTableWidgetItem(url.toString(),1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,uitem);
             }
             ui->tableWidget->resizeColumnsToContents();

             if(player->state()!=player->PlayingState)
             {

                 if(!urls.isEmpty())
                player->setMedia(urls.at(index));
                player->play();
             }
         }
}

void MainWindow::on_actionLocal_File_triggered()
{
    int index=urls.size();
    QString fname;
    fname=QFileDialog::getOpenFileName(this,tr("Open"));
    urls.append(QUrl::fromLocalFile(fname));
    //player->setMedia(QUrl::fromLocalFile(fname));
    player->setMedia(urls.at(index));
    QTableWidgetItem *uitem=new QTableWidgetItem(fname,1);
    int i=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,uitem);
    ui->tableWidget->resizeColumnsToContents();
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

void MainWindow::widgetpause(QKeyEvent *event)
{
    switch(event->key())
       {
           case Qt::Key_Space: if(player->state()==player->PlayingState)
               player->pause();
           else
               player->play();
           break;
       case Qt::Key_MediaPrevious:this->on_actionBack_triggered();
           break;
       case Qt::Key_MediaNext:this->on_actionFoward_triggered();
           break;
       case Qt::Key_MediaStop: player->stop();;
           break;
       case Qt::Key_F: if(vid->isFullScreen())
               vid->setFullScreen(false);
           else
               vid->setFullScreen(true);
           break;
       default: player->play();
       }
}

void MainWindow::on_pushButton_clicked()
{
    QUrl url;
    url=ui->lineEdit->text();
    player->setMedia(url);
    ui->lineEdit->hide();
    ui->pushButton->hide();
}

void MainWindow::on_actionBack_triggered()
{

}

void MainWindow::on_actionFoward_triggered()
{

}

void MainWindow::on_actionShow_Playlist_triggered()
{
    if(!ui->tableWidget->isVisible())
    ui->tableWidget->setVisible(true);
    else
        ui->tableWidget->setVisible(false);
}
