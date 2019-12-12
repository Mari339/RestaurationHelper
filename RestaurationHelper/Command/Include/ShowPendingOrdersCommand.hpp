#ifndef SHOWPENDINGORDERSCOMMAND_H
#define SHOWPENDINGORDERSCOMMAND_H

#include "ICommand.hpp"

using Restauration::Kitchen;

namespace Command {

class ShowPendingOrdersCommand : public ICommand {
public:
    ShowPendingOrdersCommand(std::shared_ptr<Kitchen>& kitchen) : ICommand(kitchen) {}
    bool execute() override {
        kitchen->showPendingOrders();
        return true;
    }
};

}

#endif // !SHOWPENDINGORDERSCOMMAND_H
