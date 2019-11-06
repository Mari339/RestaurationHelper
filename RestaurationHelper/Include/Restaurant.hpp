#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <memory>
#include "Menu.hpp"
#include "Kitchen.hpp"


class Restaurant {
private:
    std::vector<int> list_of_ids;
    std::string name;
    std::vector<Menu> menu;
    std::shared_ptr<Kitchen> kitchen;
public:
    Restaurant() = delete;
    Restaurant(const std::string&);
    Restaurant(const std::string&, const std::vector<int>&, const std::vector<Menu>&);
    ~Restaurant() = default;
    bool setUpKitchen();
    void run();
    void process();
private:
    bool logIn();
    bool checkForId(int);
    void showMenu();
    bool handleMenu();
};

#endif //RESTAURANT_H