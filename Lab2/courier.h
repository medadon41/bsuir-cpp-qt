#ifndef COURIER_H
#define COURIER_H
#include <QTextStream>
#include "order.h"

class courier
{
public:
    courier();

    courier(int s_number, QString s_name, QString workTime, int Capacity);

    int crNumber;

    QString crName;

    QString workTime;

    int capacity;

    int currCap = 0;

    order *orders = new order[1000];

    int distdOr = 0;
};

#endif // COURIER_H
