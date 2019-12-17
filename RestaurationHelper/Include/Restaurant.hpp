#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <memory>
#include "Menu.hpp"
#include "Kitchen.hpp"
#include "../Command/Include/ICommand.hpp"
#include "../Command/Include/AddOrderCommand.hpp"
#include "../Command/Include/EditOrderCommand.hpp"
#include "../Command/Include/DeleteOrderCommand.hpp"
#include "../Command/Include/ShowPendingOrdersCommand.hpp"
#include "../Command/Include/CloseOrderCommand.hpp"
#include "../Command/Include/ShowCompletedOrdersCommand.hpp"
#include "../pch.h"

using Command::ICommand;

namespace Restauration {

class Restaurant {
private:
    std::set<int> list_of_ids;
    std::string name;
    std::vector<Menu> menu;
    std::shared_ptr<Kitchen> kitchen;
    std::vector<std::shared_ptr<ICommand>> commands;

    const int COMMANDS_NUMBER = 6;
    enum COMMANDS {
        ADD, CLOSE, EDIT, DELETE, SHOW, SHOW_COMPLETED
    };
public:
    Restaurant();
    Restaurant(const std::string&);
    Restaurant(const std::string&, const std::set<int>&, const std::vector<Menu>&);
    bool setUpKitchen();
    void run();
    void process();
private:
    bool logIn();
    bool checkForId(int) const;
    void prepareCommands();
    void showMenu() const;
    bool handleMenu();
    char getUserChoice() const;
};

}

#endif //RESTAURANT_H