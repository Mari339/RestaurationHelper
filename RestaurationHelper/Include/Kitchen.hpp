#ifndef KITCHEN_H
#define KITCHEN_H

#include <set>
#include <iostream>
#include <deque>
#include <iterator>
#include "Order.hpp"

namespace Restauration {

class Kitchen {
private:
    constexpr static int MAX_COMPLETED_ORDERS_SIZE = 5;
    std::set<Order> pending_orders;
    std::deque<Order> completed_orders;
public:
    Kitchen() : pending_orders(), completed_orders() {}
    bool isIdInPendingOrders(const int) const;
    bool insertToPendingOrders(Order);
    bool replaceOrderInPendingOrders(const Order&, Order);
    bool deleteFromOrdersQueue(Order);
    bool updateCompletedOrders(Order);
    Order getOrder(int) const noexcept(false);
    void showPendingOrders() const;
    void showCompletedOrders() const;
private:
    void printOrder(const Order&) const;
};

}

#endif // !KITCHEN_H

