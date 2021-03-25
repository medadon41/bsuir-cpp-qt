#ifndef ORDERSARRAY_H
#define ORDERSARRAY_H

#include "order.h"


class OrdersArray
{
public:
    OrdersArray();

    order get_arr() {
        return *o_arr;
    }

    order get_elem(int n) {
        return o_arr[n];
    }

    void set_elem(int n, int number, QString address, QString deliveryRange, double weight) {
        o_arr[n] = order(number, address, deliveryRange, weight);
    }

    void set_arr(order elem, int a) {
        o_arr[a] = elem;
    }

    void set_int(int n, int s_int) {
        o_arr[n].ordNumber = s_int;
    }

    void set_double(int n, double s_dbl) {
        o_arr[n].weight = s_dbl;
    }

    void set_bool(int n, bool s_bool) {
        o_arr[n].isDistributed = s_bool;
    }

    void set_adr(int n, QString adr) {
        o_arr[n].address = adr;
    }

    void set_delRng(int n, QString del) {
        o_arr[n].deliveryRange = del;
    }

    void del_arr() {
        delete[] o_arr;
    }

private:
    order *o_arr = new order[1000];
};

#endif // ORDERSARRAY_H
