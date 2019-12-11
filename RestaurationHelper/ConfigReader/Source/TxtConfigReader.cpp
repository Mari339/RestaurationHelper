#include "../Include/TxtConfigReader.hpp"

std::map<std::string, std::string> TxtConfigReader::loadConfig(std::string path) {
    std::map<std::string, std::string> config;
    std::ifstream inFile;
    openFile(path, inFile);
    std::string key, value;
    while (inFile >> key >> value) {
        config.insert(std::make_pair(key, value));
    }
    inFile.close();
    return config;
}

void TxtConfigReader::openFile(const std::string& path, std::ifstream& inFile) {
    inFile.open(path);
    if (!inFile.is_open()) {
        std::cout << "Unable to open configuration file!";
        exit(1);
    }
}