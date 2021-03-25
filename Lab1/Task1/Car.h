#ifndef CAR_H
#define CAR_H
#include "line.h"
#include <QKeyEvent>
#include <QObject>
#include <QDebug>

class Car : public QObject, public MyLine
{
    Q_OBJECT
private:
    int XTopCoord;
    int YTopCoord;

public:
    Car(int t_XTopCoord, int t_YTopCoord);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CAR_H
