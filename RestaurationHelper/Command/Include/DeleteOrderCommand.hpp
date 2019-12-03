#ifndef DELETEORDERCOMMAND_H
#define DELETEORDERCOMMAND_H

#include "ICommand.hpp"

class DeleteOrderCommand : public ICommand {
public:
    DeleteOrderCommand(std::shared_ptr<Kitchen> kitchen) : ICommand(kitchen) {}
    bool execute() {
        return true;
    }
};

#endif // !DELETEORDERCOMMAND_H
