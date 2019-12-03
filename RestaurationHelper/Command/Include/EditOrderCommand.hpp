#ifndef EDITORDERCOMMAND_H
#define EDITORDERCOMMAND_H

#include "ICommand.hpp"

class EditOrderCommand : public ICommand {
public:
    EditOrderCommand(std::shared_ptr<Kitchen> kitchen) : ICommand(kitchen) {}
    bool execute() {
        return true;
    }
};

#endif // !EDITORDERCOMMAND_H
