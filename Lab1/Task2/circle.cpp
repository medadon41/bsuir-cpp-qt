#include "circle.h"
#include "math.h"

Circle::Circle(QObject *parent) : Figure(parent)
{

}

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRectF(-820,-630,1640,1260);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QColor(255, 38, 38), 2));
    painter->drawEllipse(-R, -R, 2 * R, 2 * R);

    painter->setPen(QPen(QColor(255, 235, 235), 2));
    painter->setBrush(QBrush(QColor(255, 235, 235)));
    painter->drawEllipse(pointCenter.x() - 6, pointCenter.y() - 6, 12, 12);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
