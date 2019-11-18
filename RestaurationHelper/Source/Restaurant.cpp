#include "../Include/Restaurant.hpp"

Restaurant::Restaurant() : name("Restaurant"), list_of_ids(1, 1), menu(), kitchen(nullptr), commands(COMMANDS_NUMBER) {}

Restaurant::Restaurant(const std::string& name) : name(name),
                                                  list_of_ids(1, 1),
                                                  menu(),
                                                  kitchen(nullptr),
                                                  commands(COMMANDS_NUMBER) {}

Restaurant::Restaurant(const std::string& name,
                       const std::vector<int>& ids,
                       const std::vector<Menu>& menu)
    : name(name), list_of_ids(ids), menu(menu), kitchen(nullptr), commands(COMMANDS_NUMBER) {}

bool Restaurant::setUpKitchen() {
    if (kitchen == nullptr) {
        kitchen = std::make_shared<Kitchen>();
        return true;
    }
    return false;
}

void Restaurant::run() {
    bool logged_in = false;
    while(!logged_in)
        logged_in = logIn();
    std::cout << "You are logged in!\n";
    process();
}

bool Restaurant::logIn() {
    std::cout << "Type your id: ";
    int id;
    std::cin >> id;
    return checkForId(id);
}

bool Restaurant::checkForId(int id) {
    for (int i : list_of_ids)
        if (i == id)
            return true;
    return false;
}

void Restaurant::process() {
    bool terminate = false;
    setUpKitchen();
    prepareCommands();
    while (!terminate) {
        showMenu();
        terminate = handleMenu();
    }
}

void Restaurant::prepareCommands() {
    commands.push_back(std::make_shared<AddOrderCommand>(kitchen, menu));
    commands.push_back(std::make_shared<CloseOrderCommand>(kitchen));
    commands.push_back(std::make_shared<ShowPendingOrdersCommand>(kitchen));
    commands.push_back(std::make_shared<ShowCompletedOrdersCommand>(kitchen));
}

void Restaurant::showMenu() {
    std::cout << "--------------------\n";
    std::cout << "       MENU\n";
    std::cout << "--------------------\n";
    std::cout << "1. Add order\n";
    std::cout << "2. Close order\n";
    std::cout << "3. Edit order\n";
    std::cout << "4. Delete order\n";
    std::cout << "5. Show orders\n";
    std::cout << "6. Show closed orders\n";
    std::cout << "9. Exit\n";
}

bool Restaurant::handleMenu() {
    std::cout << "Your choice: ";
    char choice;
    std::cin >> choice;
    switch (choice) { //TODO: obsluga wartosci zwracanej
    case '1':
        commands.at(ADD)->execute();
        break;
    case '2':
        commands.at(CLOSE)->execute();
        break;
    case '3':
        commands.at(EDIT)->execute();
        break;
    case '4':
        commands.at(DELETE)->execute();
        break;
    case '5':
        commands.at(SHOW)->execute();
        break;
    case '6':
        commands.at(SHOW_COMPLETED)->execute();
        break;
    case '9':
        return true;
    default:
        std::cout << "Wrong option!\n";
    }
    return false;
}