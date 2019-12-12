#ifndef EDITORDERCOMMAND_H
#define EDITORDERCOMMAND_H

#include "ICommand.hpp"
#include "AddOrderCommand.hpp"

using Restauration::Kitchen;
using Restauration::Order;

namespace Command {

class EditOrderCommand : public ICommand {
private:
    constexpr static int ASCII_SHIFT = 48;
    std::shared_ptr<AddOrderCommand> orders_adder;
public:
    EditOrderCommand(std::shared_ptr<Kitchen>& kitchen, std::shared_ptr<AddOrderCommand> orders_adder)
        : ICommand(kitchen), orders_adder(orders_adder) {}
    bool execute() override;
private:
    bool checkIfOrderExists(int) const;
    void showInfo(const Order& order) const;
};

}

#endif // !EDITORDERCOMMAND_H
