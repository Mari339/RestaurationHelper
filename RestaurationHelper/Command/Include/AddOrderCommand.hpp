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
    AddOrderCommand(std::shared_ptr<Kitchen>&, const std::vector<Menu>&);
    bool execute();
    Order createOrder();
private:
    std::vector<Menu> makeDishesListFromMenu();
    void showMenu();
    std::pair<Menu, bool> getMenuObject(char);
};

#endif // !ADDORDERCOMMAND_H
