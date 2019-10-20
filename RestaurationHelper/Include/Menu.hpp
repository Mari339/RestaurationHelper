#ifndef MENU_H
#define MENU_H

#include <string>


struct Menu {
    int id;
    std::string name;
    float price;

    void setMenu(int id, std::string name, float price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }
};

#endif //MENU_H