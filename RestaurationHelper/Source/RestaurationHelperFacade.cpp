#include "../Builder/Include/Configurator.hpp"
#include "Director.cpp"
#include "../Include/Restaurant.hpp"
#include <iostream>
#include <memory>

using Builder::Configurator;
using Restauration::Restaurant;

class RestaurationHelperFacade {
private:
    Director director;
public:
    RestaurationHelperFacade() : director() {}

    RestaurationHelperFacade(const std::string& path) : director(path) {}

    void runRestaurant() {
        std::shared_ptr<IBuilder> builder = std::make_shared<Configurator>();
        director.setBuilder(builder);
        director.build();
        Restaurant restaurant = std::move(builder->getRestaurant());
        restaurant.run();
    }
};