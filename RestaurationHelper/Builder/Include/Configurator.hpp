#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include "../../Include/Menu.hpp"
#include "IBuilder.hpp"
#include "../../Include/Restaurant.hpp"
#include "../../ConfigReader/Include/TxtConfigReader.hpp"
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>


class Configurator : public IBuilder {
private:
    std::map<std::string, std::string> config;
    std::vector<Menu> menu;
    std::vector<int> list_of_ids;
public:
    Restaurant getRestaurant();
    void loadConfig(std::string path = "C:\\Users\\Mari\\source\\repos\\RestaurationHelper\\RestaurationHelper\\Data\\config.ini");
    void loadMenu();
    void loadIds();
private:
    std::string getConfigValue(const std::string&);
    void openFile(const std::string&, std::ifstream&);
    void createKitchen(Restaurant&);
};

#endif //CONFIGURATOR_H