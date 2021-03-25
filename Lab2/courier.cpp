#include "courier.h"

courier::courier(int number, QString name, QString workTime, int capacity)
{
    this->crNumber = number;
    this->crName = name;
    this->workTime = workTime;
    this->capacity = capacity;
}

courier::courier() {

}
