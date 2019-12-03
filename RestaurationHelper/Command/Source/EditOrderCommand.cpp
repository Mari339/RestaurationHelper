#include "../Include/EditOrderCommand.hpp"

bool EditOrderCommand::execute() {
    int id = getOrderIdToEdit();
    if (!checkIfOrderExists(id))
        return false;
    Order to_edit = kitchen->getOrder(id);
    showInfo(to_edit);
    Order to_add = orders_adder->createOrder();
    if (to_add.getDishes().size() == 0)
        return false;
    return kitchen->replaceOrderInPendingOrders(to_edit, to_add);
}

int EditOrderCommand::getOrderIdToEdit() {
    std::cout << "Choose order ID to edit: ";
    char choice;
    std::cin >> choice;
    choice -= ASCII_SHIFT;
    return choice > 0 && choice <= 9 ? choice : 0;
}

bool EditOrderCommand::checkIfOrderExists(int id) {
    return kitchen->isIdInPendingOrders(id);
}

void EditOrderCommand::showInfo(const Order& order) {
    std::cout << "Order you want to edit:\n";
    order.show();
    std::cout << "\nCreate new order:\n";
}