#include "../Builder/Include/Configurator.hpp"
#include "Director.cpp"
#include "../Include/Restaurant.hpp"
#include <iostream>
#include <memory>

class RestaurationHelperFacade {
private:
    bool prepared;
    Director director;
public:
    RestaurationHelperFacade() : prepared(false), director() {}

    RestaurationHelperFacade(const std::string& path) : prepared(false), director(path) {}

    void runRestaurant() {
        std::shared_ptr<IBuilder> builder = std::make_shared<Configurator>();
        director.setBuilder(builder);
        director.build();
        Restaurant restaurant = builder->getRestaurant();
        restaurant.run();
        prepared = true;
    }
};