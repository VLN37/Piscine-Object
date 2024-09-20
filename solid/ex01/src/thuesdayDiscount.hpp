#pragma once

#include <ctime>

class ThuesdayDiscount : public Command {
 public:
    float get_total_price() const {
        float price = Command::get_total_price();

        return isThuesday() ? price * 0.9 : price;
    }

 private:
    bool isThuesday() const { return localtime(&time)->tm_wday == 2; }
};
