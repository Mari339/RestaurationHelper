#include "../Include/Configurator.hpp"


Restaurant Configurator::getRestaurant() {
    Restaurant output(getConfigValue("name"), list_of_ids, menu);
    return output;
}

void Configurator::loadConfig(std::string path) {
    std::ifstream inFile;
    openFile(path, inFile);
    std::string key, value;
    while (inFile >> key >> value) {
        config.insert(std::make_pair(key, value));
    }
    inFile.close();
}


void Configurator::loadMenu() {
    std::string path_to_menu = getConfigValue("menu");
    std::ifstream inFile;
    openFile(path_to_menu, inFile);
    std::string id, name, price;
    Menu temp;
    while (inFile >> id >> name >> price) {
        temp.setMenu(std::stoi(id), name, std::stof(price));
        menu.push_back(temp);
    }
    inFile.close();
}

void Configurator::loadIds() {
    std::string path_to_ids = getConfigValue("ids");
    std::ifstream inFile;
    openFile(path_to_ids, inFile);
    std::string id;
    while (inFile >> id) {
        int id_val = stoi(id);
        list_of_ids.push_back(id_val);
    }
    inFile.close();
}

std::string Configurator::getConfigValue(const std::string& key) {
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
