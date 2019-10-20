#include "../Builder/Include/IBuilder.hpp"
#include <memory>
#include <string>

class Director {
private:
    std::shared_ptr<IBuilder> builder;
    std::string path;
public:
    Director() : path("C:\\Users\\Mari\\source\\repos\\RestaurationHelper\\RestaurationHelper\\Data\\config.ini") {}
    Director(std::string path, IBuilder* builder = nullptr) : path(path), builder(builder) {}
    void setBuilder(std::shared_ptr<IBuilder> builder) {
        this->builder = builder;
    }
    void build() {
        if (builder != nullptr) {
            builder->loadConfig(path);
            builder->loadMenu();
            builder->loadIds();
        }
    }
};