#ifndef ORDER_H
#define ORDER_H
#include "Menu.hpp"
#include <vector>
#include <time.h>
#include <iostream>

namespace Restauration {

class Order {
private:
    static int id_counter;
    double price;
    std::vector<Menu> dishes;
    struct std::tm* order_time;
    const std::string COLOR_START = "\033[1;31m";
    const std::string COLOR_END = "\033[0m";
public:
    int id;
    Order(const std::vector<Menu>&&);
    Order(const Order&) = default;
    Order(Order&&);
    Order& operator=(Order&) = default;
    Order& operator=(Order&&);
    void show() const;
    std::vector<Menu> getDishes();
    void updateDishes(const std::vector<Menu>&&);
    bool operator<(const Order&) const;
private:
    void computePrice();
    void setOrderTime();
};

}

#endif // ORDER_H

