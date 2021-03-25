#ifndef ORDER_H
#define ORDER_H
#include <QTextStream>


class order
{
public:
    order();

    order(int number, QString address, QString deliveryRange, double weight);

    int ordNumber;

    QString address;

    QString deliveryRange;

    double weight;

    bool isDistributed = false;
};

#endif // ORDER_H
