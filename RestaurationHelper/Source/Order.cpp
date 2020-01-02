#include "../Include/Order.hpp"

using namespace Restauration;

int Order::id_counter = 0;

Order::Order(const std::vector<Menu>&& dishes) {
    id = ++id_counter;
    updateDishes(std::move(dishes));
    setOrderTime();
}

Order::Order(Order&& order) {
    id = order.id;
    price = order.price;
    dishes = std::move(order.dishes);
    order_time = order.order_time;
    order.order_time = nullptr;
}

Order& Order::operator=(Order&& order) {
    id = order.id;
    price = order.price;
    dishes = std::move(order.dishes);
    order_time = order.order_time;
    order.order_time = nullptr;
    return *this;
}

void Order::show() const {
    std::cout << COLOR_START << "ID: " << COLOR_END << id << ", " << COLOR_START << "DATE: " << COLOR_END << asctime(order_time)
              << COLOR_START << "TOTAL PRICE: " << COLOR_END << price << "\n"
              << COLOR_START << "DISHES: " << COLOR_END << "\n";
    for (unsigned i = 0; i < dishes.size(); i++) {
        dishes[i].show();
        std::cout << ",\n";
    }
}

std::vector<Menu> Order::getDishes() {
    return dishes;
}

void Order::updateDishes(const std::vector<Menu>&& dishes) {
    this->dishes = dishes;
    computePrice();
}

bool Order::operator<(const Order& o) const {
    return this->id < o.id;
}

void Order::computePrice() {
    price = 0;
    for (Menu m : dishes)
        price += m.price;
}

void Order::setOrderTime() {
    time_t rawtime;
    time(&rawtime);
    order_time = localtime(&rawtime);
}
