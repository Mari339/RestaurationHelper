#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "../../Include/Kitchen.hpp"

class ICommand {
protected:
    Kitchen* kitchen;
public:
    ICommand(Kitchen* kitchen) : kitchen(kitchen) {}
    virtual bool execute() = 0;
};

#endif // ICOMMAND_H

