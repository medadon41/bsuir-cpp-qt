#include "order.h"

order::order(int number, QString address, QString deliveryRange, double weight)
{
    this->ordNumber = number;
    this->address = address;
    this->deliveryRange = deliveryRange;
    this->weight = weight;
}

order::order() {

}


