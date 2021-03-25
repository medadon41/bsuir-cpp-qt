#ifndef BODY_H
#define BODY_H
#include "line.h"
#include <QKeyEvent>
#include <QObject>
#include <QDebug>

class body : public QObject, public line
{
    Q_OBJECT
private:
    int XBodyTopCoord;
    int YBodyTopCoord;

public:
    body(int t_XBodyTopCoord, int t_YBodyTopCoord);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

    void keyPressEvent(QKeyEvent *event);

    QTimer *timer;

public slots:
    void move();
};

#endif // BODY_H
