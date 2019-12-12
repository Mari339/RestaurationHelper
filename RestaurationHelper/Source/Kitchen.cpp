#include "../Include/Kitchen.hpp"

using namespace Restauration;

bool Kitchen::isIdInPendingOrders(int id) const {
    for (auto i : pending_orders)
        if (id == i.id)
            return true;
    return false;
}

bool Kitchen::insertToPendingOrders(Order order) {
    if (isIdInPendingOrders(order.id))
        return false;
    pending_orders.insert(order);
    return true;
}

bool Kitchen::replaceOrderInPendingOrders(const Order& old_order, Order new_order) {
    if (!isIdInPendingOrders(old_order.id) || isIdInPendingOrders(new_order.id))
        return false;
    pending_orders.erase(old_order);
    pending_orders.insert(new_order);
    return true;
}

bool Kitchen::deleteFromOrdersQueue(const Order& order) {
    if (!isIdInPendingOrders(order.id))
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

Order Kitchen::getOrder(int id) const {
    for (auto i : pending_orders)
        if (i.id == id)
            return i;
    throw("Given id is not in pending_orders");
}

void Kitchen::showPendingOrders() const {
    std::cout << "Number of orders: " << pending_orders.size() << "\n";
    for (Order o : pending_orders)
        printOrder(o);
}

void Kitchen::showCompletedOrders() const {
    std::cout << "Last " << completed_orders.size() << " completed orders: \n";
    for (Order o : completed_orders)
        printOrder(o);
}

void Kitchen::printOrder(const Order& o) const {
    o.show();
    std::cout << "\n";
}