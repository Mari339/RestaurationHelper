#include "../Include/AddOrderCommand.hpp"

AddOrderCommand::AddOrderCommand(Kitchen* kitchen, std::vector<Menu> menu) : ICommand::ICommand(kitchen), menu(menu) {}

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
    char choice;
    std::vector<Menu> output;
    while(true) {
        showMenu();
        std::cin >> choice;
        if (choice == 0)
            return output;
        std::pair<Menu, bool> new_dish = getMenuObject(choice);
        if (new_dish.second)
            output.push_back(new_dish.first);
        else
            std::cout << "There is no dish with given ID!\n";
    }
}

void AddOrderCommand::showMenu() {
    for (Menu m : menu) {
        m.show();
        std::cout << "\n";
    }
    std::cout << "Your choice (ID): ";
}

std::pair<Menu, bool> AddOrderCommand::getMenuObject(char choice) {
    for (Menu m : menu)
        if (m.id == choice)
            return std::make_pair(m, true);
    return std::make_pair(Menu(), false);
}