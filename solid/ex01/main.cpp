#include <cassert>
#include <command.hpp>
#include <iostream>
#include <packageReductionDiscount.hpp>
#include <thuesdayDiscount.hpp>

int main(void) {
    {
        Command *cmd = new Command;
        cmd->order("fries", 10);
        cmd->order("burguer", 10);
        std::cout << *cmd;
        delete cmd;
    }

    {
        Command *cmd = new PackageReductionDiscount;
        cmd->order("fries", 10);
        cmd->order("burguer", 10);
        std::cout << *cmd;
        delete cmd;
    }

    {
        Command *cmd = new ThuesdayDiscount;
        cmd->order("fries", 10);
        cmd->order("burguer", 10);
        std::cout << *cmd;
        delete cmd;
    }
}
