#ifndef TXTCONFIGREADER_H
#define TXTCONFIGREADER_H

#include "IConfigReader.hpp"

namespace ConfigReader {

class TxtConfigReader : public IConfigReader {
public:
    std::map<std::string, std::string> loadConfig(std::string) override;
private:
    void openFile(const std::string&, std::ifstream&);
};

}

#endif // !TXTCONFIGREADER_H
