#include "../Include/Kitchen.hpp"

bool Kitchen::isIdInPendingOrders(Order order) {
    return pending_orders.find(order) != pending_orders.end();
}

bool Kitchen::insertToPendingOrders(Order order) {
    if (isIdInPendingOrders(order))
        return false;
    pending_orders.insert(order);
    return true;
}

bool Kitchen::deleteFromOrdersQueue(Order order) {
    if (!isIdInPendingOrders(order))
        return false;
    pending_orders.erase(order);
    return true;
}

bool Kitchen::updateCompletedOrders(Order order) {
    completed_orders.push_back(order);
    if (completed_orders.size() > MAX_COMPLETED_ORDERS_SIZE)
        completed_orders.pop_front();
    return true;
}

void Kitchen::showPendingOrders() {
    for (Order o : pending_orders)
        printOrder(o);
}

void Kitchen::showCompletedOrders() {
    for (Order o : completed_orders)
        printOrder(o);
}

void Kitchen::printOrder(const Order& o) {
    o.show();
    std::cout << "\n";
}