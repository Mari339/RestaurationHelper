#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "../../Include/Kitchen.hpp"
#include <memory>

class ICommand {
private:
    constexpr static int ASCII_SHIFT = 48;
protected:
    std::shared_ptr<Kitchen> kitchen;
    int getOrderId(const std::string msg) {
        std::cout << msg;
        char choice;
        std::cin >> choice;
        choice -= ASCII_SHIFT;
        return choice > 0 && choice <= 9 ? choice : 0;
    }
public:
    ICommand(std::shared_ptr<Kitchen>& kitchen) : kitchen(kitchen) {}
    virtual bool execute() = 0;
};

#endif // ICOMMAND_H

