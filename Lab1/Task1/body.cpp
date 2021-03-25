#include "body.h"
#include <QPainter>
#include <line.h>
#include <QBrush>
#include <QDebug>
#include <QTimer>

body::body(int XBodyTopCoord, int YBodyTopCoord):line(0, 0, 0, 0), XBodyTopCoord(XBodyTopCoord), YBodyTopCoord(YBodyTopCoord){}

void body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    // body
    painter->setPen(QColor(133, 77, 0));
       painter->drawLine(XBodyTopCoord,YBodyTopCoord,XBodyTopCoord+160,YBodyTopCoord);
       painter->drawLine(XBodyTopCoord,YBodyTopCoord+40,XBodyTopCoord+160,YBodyTopCoord+40);
       painter->drawLine(XBodyTopCoord,YBodyTopCoord,XBodyTopCoord,YBodyTopCoord+40);
       painter->drawLine(XBodyTopCoord+160,YBodyTopCoord,XBodyTopCoord+160,YBodyTopCoord+40);
       painter->drawEllipse(XBodyTopCoord,YBodyTopCoord+40, 40, 40);
       painter->drawEllipse(XBodyTopCoord+120,YBodyTopCoord+40 , 40 , 40);
}

void body::keyPressEvent(QKeyEvent *event){

    timer = new QTimer;

    if (event->key() == Qt::Key_Space){
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
    }
}

void body::move(){
    setPos(x()+3, y());

    if (y() < YBodyTopCoord-175) timer->stop();
}


QRectF body::boundingRect() const
{
    return QRectF(XBodyTopCoord, YBodyTopCoord, 160, 85);
}

