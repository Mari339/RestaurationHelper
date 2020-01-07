#include "../Include/Kitchen.hpp"

using namespace Restauration;

bool Kitchen::isIdInPendingOrders(int id) const {
    return std::any_of(pending_orders.begin(), pending_orders.end(), [&id](auto &i) { return i.id == id; });
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

bool Kitchen::deleteFromOrdersQueue(Order order) {
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
    auto result = std::find_if(pending_orders.begin(), pending_orders.end(), [&id](auto &i) { return i.id == id; });
    if (result != pending_orders.end())
        return *result;
    throw("Given id is not in pending_orders");
}

void Kitchen::showPendingOrders() const {
    std::cout << "Number of orders: " << pending_orders.size() << "\n";
    std::for_each(pending_orders.begin(),
                  pending_orders.end(),
                  std::bind(&Kitchen::printOrder, this, std::placeholders::_1));
}

void Kitchen::showCompletedOrders() const {
    std::cout << "Last " << completed_orders.size() << " completed orders: \n";
    std::for_each(completed_orders.begin(),
                  completed_orders.end(),
                  std::bind(&Kitchen::printOrder, this, std::placeholders::_1));
}

void Kitchen::printOrder(const Order& o) const {
    o.show();
    std::cout << "\n";
}