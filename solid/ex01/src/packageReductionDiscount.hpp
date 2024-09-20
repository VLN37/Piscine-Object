#pragma once

#include <command.hpp>

class PackageReductionDiscount : public Command {
 public:
    float get_total_price() const {
        float price = Command::get_total_price();

        return price > 150 ? price - 10 : price;
    }
};
