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
#include "../pch.h"


class Restaurant {
private:
    std::vector<int> list_of_ids;
    std::string name;
    std::vector<Menu> menu;
    std::shared_ptr<Kitchen> kitchen;
    std::vector<ICommand*> commands;

    const int COMMANDS_NUMBER = 5;
    enum COMMANDS {
        ADD, DEL, EDIT, CLOSE, SHOW
    };
public:
    Restaurant();
    Restaurant(const std::string&);
    Restaurant(const std::string&, const std::vector<int>&, const std::vector<Menu>&);
    ~Restaurant();
    bool setUpKitchen();
    void run();
    void process();
private:
    bool logIn();
    bool checkForId(int);
    void prepareCommands();
    void showMenu();
    bool handleMenu();
};

#endif //RESTAURANT_H