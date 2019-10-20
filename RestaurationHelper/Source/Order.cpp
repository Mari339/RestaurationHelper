#include "../Include/Order.hpp"

int Order::id_counter = 0;

Order::Order(std::vector<Menu> dishes) {
    id = ++id_counter;
    updateDishes(dishes);
    setOrderTime();
}

double Order::computePrice() {
    return 0.0;
}

void Order::setOrderTime() {

}

void Order::show() {

}

void Order::updateDishes(std::vector<Menu> dishes) {

}

bool Order::operator<(const Order o) const {
    return true;
}