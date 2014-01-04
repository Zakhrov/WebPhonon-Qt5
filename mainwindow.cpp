#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QMediaPlaylist>
#include "dropwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->hide();
    vid=new DropWidget(this);
    med=new Phonon::MediaObject(this);
    sndout=new Phonon::AudioOutput(Phonon::VideoCategory,this);
    Phonon::createPath(med,vid);
    Phonon::createPath(med,sndout);
    ui->gridLayout->addWidget(vid);
    ui->pushButton->hide();
//    ui->verticalSlider->setRange(0,100);
//    ui->verticalSlider->setValue(player->volume());
//    ui->horizontalSlider->setRange(0,player->duration()/1000);
//    connect(player, SIGNAL(durationChanged(qint64)), SLOT(durationChanged(qint64)));
//    connect(player, SIGNAL(positionChanged(qint64)), SLOT(positionChanged(qint64)));
//    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)), SLOT(seek(int)));
//    connect(ui->verticalSlider,SIGNAL(sliderMoved(int)),player,SLOT(setVolume(int)));
    ui->seekSlider->setMediaObject(med);
    ui->volumeSlider->setAudioOutput(sndout);
    connect(med,SIGNAL(aboutToFinish()),this,SLOT(next()));
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
    int index=sources.size();
    if (mimeData->hasUrls()) {
             foreach (QUrl url, mimeData->urls()) {
                 sources.append(url);
                QTableWidgetItem *uitem=new QTableWidgetItem(url.toString(),1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,uitem);
             }
             ui->tableWidget->resizeColumnsToContents();

             if(med->state()!=Phonon::PlayingState)
             {

                 if(!sources.isEmpty())
                med->setCurrentSource(sources.at(index));
                med->play();
             }
         }
}

void MainWindow::on_actionLocal_File_triggered()
{
    int i;
    int index=sources.size();
    QStringList fnames;
    fnames=QFileDialog::getOpenFileNames(this,tr("Open"));
    foreach(QString fname,fnames)
    {
        sources.append(Phonon::MediaSource(QUrl::fromLocalFile(fname)));
    //player->setMedia(QUrl::fromLocalFile(fname));

    QTableWidgetItem *uitem=new QTableWidgetItem(fname,1);
     i=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,uitem);
    }
    ui->tableWidget->resizeColumnsToContents();
    med->setCurrentSource(sources.at(index));
    med->play();

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
    med->play();
}

void MainWindow::on_actionPause_triggered()
{
    if(med->state()==Phonon::PlayingState)
        med->pause();
    else
        med->play();
}

void MainWindow::on_actionStop_triggered()
{
    med->stop();
}

void MainWindow::on_actionFull_Screen_triggered()
{
    if(vid->isFullScreen()==false){

        vid->setFullScreen(true);
        vid->setFocus();

    }
    else
    {
        vid->setFullScreen(false);
        //ui->gridLayout->addWidget(vid);
    }
}

void MainWindow::next()
{
    this->on_actionFoward_triggered();
}

//void MainWindow::positionChanged(qint64 progress)
//{
//    if(!ui->horizontalSlider->isSliderDown())
//        ui->horizontalSlider->setValue(progress / 1000);
//}

//void MainWindow::durationChanged(qint64 duration)
//{
//    ui->horizontalSlider->setMaximum(duration /1000);
//}

//void MainWindow::seek(int secs)
//{
//    player->setPosition(secs*1000);
//}

void MainWindow::widgetpause(QKeyEvent *event)
{
    switch(event->key())
       {
           case Qt::Key_Space: if(med->state()==Phonon::PlayingState)
               med->pause();
           else
               med->play();
           break;
       case Qt::Key_MediaPrevious:this->on_actionBack_triggered();
           break;
       case Qt::Key_MediaNext:this->on_actionFoward_triggered();
           break;
       case Qt::Key_MediaStop: med->stop();;
           break;
       case Qt::Key_F: if(vid->isFullScreen())
               vid->setFullScreen(false);
           else
               vid->setFullScreen(true);
           break;
       default: med->play();
       }
}

void MainWindow::on_pushButton_clicked()
{
    int index=sources.size();
    QUrl url;
    url=ui->lineEdit->text();
    sources.append(url);
    med->setCurrentSource(sources.at(index));
    ui->lineEdit->hide();
    ui->pushButton->hide();
    med->play();
}

void MainWindow::on_actionBack_triggered()
{
    int index=sources.indexOf(med->currentSource());
    if(index!=0)
        med->setCurrentSource(sources.at(index-1));
    else
        med->setCurrentSource(sources.at(index));
    med->play();
}

void MainWindow::on_actionFoward_triggered()
{
    int index=sources.indexOf(med->currentSource())+1;
    if(sources.size()>index)
        med->setCurrentSource(sources.at(index));

    med->play();
}

void MainWindow::on_actionShow_Playlist_triggered()
{
    if(!ui->tableWidget->isVisible())
    ui->tableWidget->setVisible(true);
    else
        ui->tableWidget->setVisible(false);
}
