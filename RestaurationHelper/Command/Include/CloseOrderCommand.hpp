#ifndef CLOSEORDERCOMMAND_H
#define CLOSEORDERCOMMAND_H

#include "ICommand.hpp"

using Restauration::Kitchen;

namespace Command {

class CloseOrderCommand : public ICommand {
public:
    CloseOrderCommand(std::shared_ptr<Kitchen>);
    bool execute();
};

}

#endif