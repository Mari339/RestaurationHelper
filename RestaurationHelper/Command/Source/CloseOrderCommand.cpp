#include "../Include/CloseOrderCommand.hpp"

CloseOrderCommand::CloseOrderCommand(std::shared_ptr<Kitchen> kitchen) : ICommand(kitchen) {}

bool CloseOrderCommand::execute() {
    int id = getIdToClose();
    try {
        Order order = kitchen->getOrder(id);
        bool result = kitchen->deleteFromOrdersQueue(order);
        return result && kitchen->updateCompletedOrders(order);
    }
    catch (const char* msg) {
        std::cout << msg << "\n";
        return false;
    }
}

int CloseOrderCommand::getIdToClose() {
    std::cout << "Chose order id to close: ";
    int id;
    std::cin >> id;
    return id;
}