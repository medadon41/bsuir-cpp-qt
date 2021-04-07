#ifndef COURIERSARRAY_H
#define COURIERSARRAY_H

#include "courier.h"
#include "order.h"

class CouriersArray
{
public:
    CouriersArray();

    courier get_arr() {
        return *c_arr;
    }

    courier get_elem(int n) {
        return c_arr[n];
    }

    void set_elem(int n, int s_number, QString s_name, QString workTime, int Capacity) {
        c_arr[n] = courier(s_number, s_name, workTime, Capacity);
    }

    void set_arr(courier elem, int a) {
        c_arr[a] = elem;
    }

    void set_int(int n, int s_int) {
        c_arr[n].capacity = s_int;
    }

    void set_name(int n, QString s_name) {
        c_arr[n].crName = s_name;
    }

    void set_workTime(int n, QString s_wTime) {
        c_arr[n].workTime = s_wTime;
    }

    void set_cap(int n, int cap) {
        c_arr[n].capacity = cap;
    }

    void set_ord(int n, int m, order e) {
        c_arr[n].orders[m] = e;
    }

    void add_cap(int n, int wcap) {
        c_arr[n].currCap += wcap;
    }

    void inc_ords(int n) {
        ++c_arr[n].distdOr;
    }

    void del_arr() {
        delete[] c_arr;
    }

private:
    courier *c_arr = new courier[1000];
};
#endif // COURIERSARRAY_H
