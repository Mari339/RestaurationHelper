#include "../Include/AddOrderCommand.hpp"
#include <vector>

using namespace Command;

AddOrderCommand::AddOrderCommand(std::shared_ptr<Kitchen>& kitchen, const std::vector<Menu>& menu)
    : ICommand::ICommand(kitchen), menu(menu) {}

bool AddOrderCommand::execute() {
    Order order = createOrder();
    if (order.getDishes().size() == 0)
        return false;
    return kitchen->insertToPendingOrders(order);
}

Order AddOrderCommand::createOrder() {
    return Order(makeDishesListFromMenu());
}

std::vector<Menu> AddOrderCommand::makeDishesListFromMenu() {
    std::vector<Menu> output;
    while(true) {
        showMenu();
        int choice = getOrderId("Your choice (ID, 0 to confirm): ");
        if (choice == 0)
            return output;
        std::pair<Menu, bool> new_dish = getMenuObject(choice);
        if (new_dish.second)
            output.push_back(new_dish.first);
        else
            std::cout << "There is no dish with given ID!\n";
    }
}

void AddOrderCommand::showMenu() const {
    for (Menu m : menu) {
        m.show();
        std::cout << "\n";
    }
}

std::pair<Menu, bool> AddOrderCommand::getMenuObject(char choice) {
    for (Menu m : menu)
        if (m.id == choice - '0')
            return std::make_pair(m, true);
    return std::make_pair(Menu(), false);
}