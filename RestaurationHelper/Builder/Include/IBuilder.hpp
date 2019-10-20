#ifndef IBUILDER_H
#define IBUILDER_H

#include "../../Include/Restaurant.hpp"

class IBuilder {
public:
    virtual Restaurant getRestaurant() = 0;
    virtual void loadConfig(std::string) = 0;
    virtual void loadMenu() = 0;
    virtual void loadIds() = 0;
};

#endif //IBUILDER_H