#include "../Builder/Include/Configurator.hpp"
#include "Director.cpp"
#include "../Include/Restaurant.hpp"
#include <iostream>
#include <memory>

class RestaurationHelperFacade {
private:
    Restaurant restaurant;
    bool prepared;
    Director director;
public:
    RestaurationHelperFacade() : restaurant(), prepared(false), director() {}

    RestaurationHelperFacade(std::string path) :restaurant(), prepared(false), director(path) {}

    void prepareRestaurant() {
        std::shared_ptr<IBuilder> builder = std::make_shared<Configurator>();
        director.setBuilder(builder);
        director.build();
        restaurant = builder->getRestaurant();
        prepared = true;
    }
    void runRestaurant() {
        if (prepared)
            restaurant.run();
        else
            std::cout << "Restaurant is not prepared!\n";
    }
};