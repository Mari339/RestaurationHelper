#include "../Include/Kitchen.hpp"

bool Kitchen::isIdInPendingOrders(Order order) {
    return pending_orders.find(order) != pending_orders.end();
}

bool Kitchen::insertToPendingOrders(Order order) {
    if (isIdInPendingOrders(order))
        return false;
    pending_orders.emplace(order);
    return true;
}

bool Kitchen::deleteFromOrdersQueue(Order order) {
    if (!isIdInPendingOrders(order))
        return false;
    pending_orders.erase(order);
    return true;
}