#include "../Include/DeleteOrderCommand.hpp"

using namespace Command;

bool DeleteOrderCommand::execute() {
    int id = getOrderId("Choose order ID to delete (0 to cancel): ");
    if (id == 0)
        return false;
    if (kitchen->isIdInPendingOrders(id)) {
        Order to_delete = kitchen->getOrder(id);
        return kitchen->deleteFromOrdersQueue(to_delete);
    }
    std::cout << "There is no Order with given ID.\n";
    return false;
}