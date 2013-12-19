#include "dropwidget.h"
#include <QtGui>
#include <QWidget>
#include <QUrl>

DropWidget::DropWidget(QWidget *parent) :
    QVideoWidget(parent)
{
    setAcceptDrops(true);
    //setAttribute(Qt::WA_TransparentForMouseEvents);
    setCursor(Qt::BlankCursor);

    setFocus();
}
void DropWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();

}

void DropWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}


void DropWidget::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls())
        emit geturls(event->mimeData());
}

void DropWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->type()==QEvent::MouseButtonDblClick)
    {
        if(!this->isFullScreen())
            this->setFullScreen(true);
        else
            this->setFullScreen(false);
    }

}

void DropWidget::mouseMoveEvent(QMouseEvent *event)
{

//    if(event->type()==QEvent::MouseMove)

    if(event->type()==QEvent::MouseMove&&this->isFullScreen())
    {
            setCursor(Qt::BlankCursor);
    }
    else if(event->type()==QEvent::MouseMove&&!this->isFullScreen())

    {
        if(this->cursor().shape()==Qt::BlankCursor)
        setCursor(Qt::ArrowCursor);
        else
            setCursor(Qt::BlankCursor);
    }
    else
        setCursor(Qt::BlankCursor);

}

void DropWidget::keyPressEvent(QKeyEvent *event)
{


        emit capturespace(event);


}