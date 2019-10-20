#ifndef KITCHEN_H
#define KITCHEN_H

#include <set>
#include <iostream>
#include "Order.hpp"

class Kitchen {
private:
    std::set<Order> pending_orders;
    std::set<Order> completed_orders;
public:
    bool isIdInPendingOrders(Order);
    bool insertToPendingOrders(Order);
    bool deleteFromOrdersQueue(Order);
    bool updateCompletedOrders(Order);
    void showPendingOrders();
    void showCompletedOrders();
};

#endif // !KITCHEN_H

