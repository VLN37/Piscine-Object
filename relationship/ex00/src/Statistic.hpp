#pragma once

#include <iostream>

class Statistic {
 public:
    Statistic() : level(0), exp(0) {}

    int level;
    int exp;

    friend std::ostream& operator<<(std::ostream& o, const Statistic& rhs) {
        return o << "[Stats] - " << "Level: " << rhs.level << " Exp: " << rhs.exp
                 << "\n";
    }
};
