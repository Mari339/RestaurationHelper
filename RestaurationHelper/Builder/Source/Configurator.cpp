#include "../Include/Configurator.hpp"


using namespace Builder;
using ConfigReader::TxtConfigReader;


Restaurant Configurator::getRestaurant() {
    Restaurant output(getConfigValue("name"), std::move(list_of_ids), std::move(menu));
    return output;
}

void Configurator::loadConfig(std::string path) {
    TxtConfigReader reader;
    config = reader.loadConfig(path);
}


void Configurator::loadMenu() {
    std::string path_to_menu = getConfigValue("menu");
    std::ifstream inFile;
    openFile(path_to_menu, inFile);
    std::string id, name, price;
    Restauration::Menu temp;
    while (inFile >> id >> name >> price) {
        temp.setMenu(std::stoi(id), name, std::stof(price));
        menu.push_back(temp);
    }
    inFile.close();
}

void Configurator::loadIds() {
    list_of_ids = std::set<int>();
    std::string path_to_ids = getConfigValue("ids");
    std::ifstream inFile;
    openFile(path_to_ids, inFile);
    std::string id;
    while (inFile >> id) {
        int id_val = stoi(id);
        list_of_ids.insert(id_val);
    }
    inFile.close();
}

std::string Configurator::getConfigValue(const std::string& key) const {
    return config.find(key)->second;
}

void Configurator::openFile(const std::string& path, std::ifstream& inFile) {
    inFile.open(path);
    if (!inFile) {
        std::cout << "Unable to open configuration file!";
        exit(1);
    }
}

void Configurator::createKitchen(Restaurant& restaurant) {
    restaurant.setUpKitchen();
}
