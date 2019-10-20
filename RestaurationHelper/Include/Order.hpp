#ifndef ORDER_H
#define ORDER_H
#include "Menu.hpp"
#include <vector>
#include <time.h>

class Order {
private:
    static int id_counter;
    int id;
    double price;
    std::vector<Menu> dishes;
    struct std::tm order_time;
    double computePrice();
    void setOrderTime();
public:
    Order(std::vector<Menu> dishes);
    void show();
    void updateDishes(std::vector<Menu> dishes); //w konstruktorze to wolamy
    bool operator<(const Order o) const;
    //bool operator==(Order o);
    //bool operator>(Order o); moze nie trzeba
};

#endif // !ORDERS_H

