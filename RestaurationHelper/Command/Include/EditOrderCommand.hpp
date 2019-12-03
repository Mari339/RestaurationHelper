#ifndef EDITORDERCOMMAND_H
#define EDITORDERCOMMAND_H

#include "ICommand.hpp"
#include "AddOrderCommand.hpp"

class EditOrderCommand : public ICommand {
private:
    constexpr static int ASCII_SHIFT = 48;
    std::shared_ptr<AddOrderCommand> orders_adder;
public:
    EditOrderCommand(std::shared_ptr<Kitchen>& kitchen, std::shared_ptr<AddOrderCommand>& orders_adder)
        : ICommand(kitchen), orders_adder(orders_adder) {}
    bool execute();
private:
    int getOrderIdToEdit();
    bool checkIfOrderExists(int);
    void showInfo(const Order& order);
};

#endif // !EDITORDERCOMMAND_H
