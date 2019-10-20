#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>


class Restaurant {
private:
    std::vector<int> list_of_ids;
    std::string name;
public:
    Restaurant();
    Restaurant(std::string);
    Restaurant(std::string, std::vector<int>);
    ~Restaurant() = default;
    void run();
    void process();
private:
    bool logIn();
    bool checkForId(int);
    void showMenu();
    bool handleMenu();
};

#endif //RESTAURANT_H