#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>

class line : public QGraphicsItem{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

    line(int t_x1, int t_y1, int t_x2, int t_y2);

    line();

private:
    int x1, y1, x2, y2;
};

#endif // LINE_H
