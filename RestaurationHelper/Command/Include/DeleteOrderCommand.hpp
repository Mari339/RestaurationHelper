#ifndef DELETEORDERCOMMAND_H
#define DELETEORDERCOMMAND_H

#include "ICommand.hpp"

namespace Command {

class DeleteOrderCommand : public ICommand {
public:
    DeleteOrderCommand(std::shared_ptr<Kitchen> kitchen) : ICommand(kitchen) {}
    bool execute();
};

}

#endif // !DELETEORDERCOMMAND_H
