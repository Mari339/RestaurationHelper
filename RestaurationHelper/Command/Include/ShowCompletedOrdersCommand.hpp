#ifndef SHOWCOMPLETEDORDERSCOMMAND_H
#define SHOWCOMPLETEDORDERSCOMMAND_H

#include "ICommand.hpp"

class ShowCompletedOrdersCommand : public ICommand {
public:
    ShowCompletedOrdersCommand(std::shared_ptr<Kitchen> kitchen) : ICommand(kitchen) {}
    bool execute() {
        kitchen->showCompletedOrders();
        return true;
    }
};

#endif // !SHOWCOMPLETEDORDERSCOMMAND_H
