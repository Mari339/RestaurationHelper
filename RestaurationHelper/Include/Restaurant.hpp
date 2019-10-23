#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include "Menu.hpp"


class Restaurant {
private:
    std::vector<int> list_of_ids;
    std::string name;
    std::vector<Menu> menu;
public:
    Restaurant();
    Restaurant(const std::string&);
    Restaurant(const std::string&, const std::vector<int>&, const std::vector<Menu>&);
    ~Restaurant() = default;
    void run();
    void process();
private:
    bool logIn();
    bool checkForId(int);
    void showMenu();
    bool handleMenu();
};

#endif //RESTAURANT_H