#include <QApplication>
#include <QGraphicsScene>
#include "line.h"
#include "body.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 800, 400);

    body *bodytype = new body(10, 20);

    scene->addItem(bodytype);

    bodytype->setFlag(QGraphicsItem::ItemIsFocusable);
    bodytype->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
