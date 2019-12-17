#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include "../../Include/Menu.hpp"
#include "IBuilder.hpp"
#include "../../Include/Restaurant.hpp"
#include "../../ConfigReader/Include/TxtConfigReader.hpp"
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using Restauration::Restaurant;

namespace Builder {

class Configurator : public IBuilder {
private:
    std::map<std::string, std::string> config;
    std::vector<Restauration::Menu> menu;
    std::set<int> list_of_ids;
public:
    Restaurant getRestaurant() override;
    void loadConfig(std::string path = "C:\\Users\\Mari\\source\\repos\\RestaurationHelper\\RestaurationHelper\\Data\\config.ini") override;
    void loadMenu() override;
    void loadIds() override;
private:
    std::string getConfigValue(const std::string&) const;
    void openFile(const std::string&, std::ifstream&);
    void createKitchen(Restaurant&);
};

}

#endif //CONFIGURATOR_H