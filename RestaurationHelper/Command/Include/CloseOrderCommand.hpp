#ifndef CLOSEORDERCOMMAND_H
#define CLOSEORDERCOMMAND_H

#include "ICommand.hpp"

class CloseOrderCommand : public ICommand {
public:
    CloseOrderCommand(std::shared_ptr<Kitchen>);
    bool execute();
private:
    int getIdToClose();
};

#endif