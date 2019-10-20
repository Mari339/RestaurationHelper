#ifndef ORDER_H
#define ORDER_H
#include "Menu.hpp"
#include <vector>
#include <time.h>
#include <iostream>

class Order {
private:
    static int id_counter;
    int id;
    double price;
    std::vector<Menu> dishes;
    struct std::tm* order_time;
public:
    Order(const std::vector<Menu>& dishes);
    void show();
    void updateDishes(const std::vector<Menu>&);
    bool operator<(const Order&) const;
private:
    void computePrice();
    void setOrderTime();
};

#endif // ORDER_H

