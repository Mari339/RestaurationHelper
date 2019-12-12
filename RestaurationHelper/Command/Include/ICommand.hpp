#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "../../Include/Kitchen.hpp"
#include <memory>

namespace Command {

class ICommand {
protected:
    std::shared_ptr<Kitchen> kitchen;
    int getOrderId(const std::string msg) {
        try {
            std::cout << msg;
            int choice;
            std::cin >> choice;
            return choice;
        }
        catch (...) {
            std::cout << "Wrong input value";
            return 0;
        }
    }
public:
    ICommand(std::shared_ptr<Kitchen>& kitchen) : kitchen(kitchen) {}
    virtual bool execute() = 0;
};

}

#endif // ICOMMAND_H

