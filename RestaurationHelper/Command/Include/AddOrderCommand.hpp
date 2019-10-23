#ifndef ADDORDERCOMMAND_H
#define ADDORDERCOMMAND_H

#include "ICommand.hpp"
#include "../../Include/Menu.hpp"
#include "../../Include/Order.hpp"
#include <vector>
#include <iostream>

class AddOrderCommand : public ICommand {
private:
    std::vector<Menu> menu;
public:
    AddOrderCommand(Kitchen* kitchen, const std::vector<Menu>&);
    bool execute();
private:
    Order createOrder();
    std::vector<Menu> makeDishesListFromMenu();
    void showMenu();
    std::pair<Menu, bool> getMenuObject(char);
};

#endif // !ADDORDERCOMMAND_H
