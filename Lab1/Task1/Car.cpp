#include "Car.h"
#include <QPainter>
#include <line.h>
#include <QBrush>
#include <QDebug>
#include <QTimer>

Car::Car(int XTopCoord, int YTopCoord):MyLine(0, 0, 0, 0), XTopCoord(XTopCoord), YTopCoord(YTopCoord){}

void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    // body
    painter->drawLine(XTopCoord,YTopCoord,XTopCoord+250,YTopCoord);
    painter->drawLine(XTopCoord,YTopCoord+100,XTopCoord+250,YTopCoord+100);
    painter->drawLine(XTopCoord,YTopCoord,XTopCoord,YTopCoord+100);
    painter->drawLine(XTopCoord+250,YTopCoord,XTopCoord+250,YTopCoord+100);
    // wheel
    painter->drawEllipse(XTopCoord, YTopCoord+101, 50, 50);
    painter->drawEllipse(XTopCoord+200, YTopCoord+101, 50, 50);
    // head
    painter->drawLine(XTopCoord+180,YTopCoord-70,XTopCoord+250,YTopCoord-70);
    painter->drawLine(XTopCoord+180,YTopCoord,XTopCoord+180,YTopCoord-70);
    painter->drawLine(XTopCoord+250,YTopCoord,XTopCoord+250,YTopCoord-70);
    // fasteners
    painter->drawLine(XTopCoord,YTopCoord,XTopCoord,YTopCoord-70);
    painter->drawLine(XTopCoord+167,YTopCoord,XTopCoord+167,YTopCoord-70);
}
