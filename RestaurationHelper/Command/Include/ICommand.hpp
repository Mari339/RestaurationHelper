#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "../../Include/Kitchen.hpp"
#include <memory>

class ICommand {
protected:
    std::shared_ptr<Kitchen> kitchen;
public:
    ICommand(std::shared_ptr<Kitchen> kitchen) : kitchen(kitchen) {}
    virtual bool execute() = 0;
};

#endif // ICOMMAND_H

