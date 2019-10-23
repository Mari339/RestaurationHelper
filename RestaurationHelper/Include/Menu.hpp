#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>


struct Menu {
    int id;
    std::string name;
    float price;

    void setMenu(int id, std::string name, float price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }
    void show() const {
        std::cout << "ID: " << id << ", NAME: " << name << ", PRICE: " << price;
    }
};

#endif //MENU_H