#ifndef ICONFIGREADER_H
#define ICONFIGREADER_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>

class IConfigReader {
public:
    virtual std::map<std::string, std::string> loadConfig(std::string) = 0;
};

#endif // !ICONFIGREADER_H
