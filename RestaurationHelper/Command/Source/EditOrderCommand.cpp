#include "../Include/EditOrderCommand.hpp"

using namespace Command;

bool EditOrderCommand::execute() {
    int id = getOrderId("Choose order ID to edit (0 to cancel): ");
    if (!checkIfOrderExists(id))
        return false;
    Order to_edit = kitchen->getOrder(id);
    showInfo(to_edit);
    Order to_add = orders_adder->createOrder();
    if (to_add.getDishes().size() == 0)
        return false;
    return kitchen->replaceOrderInPendingOrders(to_edit, to_add);
}

bool EditOrderCommand::checkIfOrderExists(int id) const {
    return kitchen->isIdInPendingOrders(id);
}

void EditOrderCommand::showInfo(const Order& order) const {
    std::cout << "Order you want to edit:\n";
    order.show();
    std::cout << "\nCreate new order:\n";
}