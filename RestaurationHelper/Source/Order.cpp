#include "../Include/Order.hpp"

using namespace Restauration;

int Order::id_counter = 0;

Order::Order(const std::vector<Menu>&& dishes) {
    id = ++id_counter;
    updateDishes(std::move(dishes));
    setOrderTime();
}

void Order::show() const {
    std::cout << "ID: " << id << ", DATE: " << asctime(order_time)
              << "TOTAL PRICE:" << price << "\n"
              << "DISHES: " << "\n";
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
