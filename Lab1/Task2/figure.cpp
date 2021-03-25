#include "figure.h"
#include <QDebug>

Figure::Figure(QObject *parent) : QObject(parent), QGraphicsItem()
{
    timer = new QTimer();
    timer->setInterval(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(scale(bool zoom)));
}

Figure::~Figure()
{

}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QColor(255, 38, 38), 3));
    painter->setBrush(QColor(255, 38, 38));

    for (int i = 1; i < (int)points.size(); i++)
            painter->drawLine(points[i - 1], points[(i)]);

    if (paintDone && (int)points.size() > 0)
    {
        painter->setPen(QPen(QColor(255, 235, 235), 2));
        painter->setBrush(QBrush(QColor(255, 235, 235)));
        painter->drawEllipse(pointCenter.x() - 6, pointCenter.y() - 6, 12, 12);
    }

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

QRectF Figure::boundingRect() const
{
    return QRectF(-820,-630,1640,1260);
}

void Figure::setFlags()
{
    setFlag(QGraphicsItem::ItemIsMovable);
}

double Figure::getPerimeter()
{
    if (n == 0)
        P = 2 * PI * R;
    else
    {
        int a = 0;
        P = 0;
        a = 2 * R * sin(PI / n);
        P = n * a;
    }
    return P / 6;
}

double Figure::getArea()
{
    if (n == 0)
        S = PI * R * R;
    else
        S = n * R * R * 0.5 * sin(2 * PI / n);
    return S / 36;
}

void Figure::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    setCenter(event->pos());
    emit signalChanges();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Figure::setCenter(QPointF newCenter)
{
    emit signalChanges();
    pointCenter.setX(newCenter.x());
    pointCenter.setY(newCenter.y());
}

void Figure::changeSize(int valueN, int valueR)
{
    n = valueN;
    R = valueR;

    if (!paintMode)
        points.clear();
    else
    {
        for (int i = 0; i < (int)points.size(); i++)
            points[i] = {pointCenter.x() + ((points[i].x() - pointCenter.x()) / percent) * (R / 30), pointCenter.y() + ((points[i].y() - pointCenter.y()) / percent) * (R / 30)};
        percent = R;
    }
    update();
}

void Figure::rotation(int value)
{
    setTransform(QTransform().translate(pointCenter.x(), pointCenter.y()).rotate(value).translate(-pointCenter.x(), -pointCenter.y()));
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (paintMode && !paintDone)
    {
        paintDone = false;
        points.clear();
        QPointF point = event->scenePos();
        points.push_back(point);
        startPoint = event->scenePos();
        previousPoint = event->scenePos();
        update();
    }
    else
    {
        cursorPressed(event);
        QGraphicsItem::mousePressEvent(event);
    }
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (paintMode && !paintDone)
    {
        paintDone = false;
        QPointF point = event->scenePos();
        points.push_back(point);
        previousPoint = event->scenePos();
        update();
    }
    else
    {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (paintMode && !paintDone)
    {
        paintDone = true;

        pointCenter = startPoint;

        update();
        emit signalChanges();
    }
    else
    {
        cursorReleased(event);
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

void Figure::cursorPressed(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void Figure::cursorReleased(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}
