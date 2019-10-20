#include "../Include/Configurator.hpp"
#include <iostream>
#include <string>


Restaurant Configurator::getRestaurant() {
    return Restaurant(getConfigValue("name"), list_of_ids);
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
    while (inFile >> id >> name >> price) {
        Menu temp;
        temp.setMenu(std::stoi(id), name, std::stof(price));
        menu.push_back(temp);
    }
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
}

std::string Configurator::getConfigValue(std::string key) {
    return config.find(key)->second;
}

void Configurator::openFile(std::string path, std::ifstream& inFile) {
    inFile.open(path);
    if (!inFile) {
        std::cout << "Unable to open configuration file!";
        exit(1);
    }
}