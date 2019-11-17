#ifndef KITCHEN_H
#define KITCHEN_H

#include <set>
#include <iostream>
#include <deque>
#include "Order.hpp"

class Kitchen {
private:
    constexpr static int MAX_COMPLETED_ORDERS_SIZE = 5;
    std::set<Order> pending_orders;
    std::deque<Order> completed_orders;
public:
    Kitchen() : pending_orders(), completed_orders() {}
    bool isIdInPendingOrders(Order);
    bool insertToPendingOrders(Order);
    bool deleteFromOrdersQueue(Order);
    bool updateCompletedOrders(Order);
    void showPendingOrders();
    void showCompletedOrders();
private:
    void printOrder(const Order&);
};

#endif // !KITCHEN_H

