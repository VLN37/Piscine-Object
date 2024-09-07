#pragma once

#include <iostream>

class Stats {
 public:
    Stats() : level(0), exp(0) {}

    const int &get_level() const { return level; }
    const int &get_exp() const { return exp; }

 private:
    int level;
    int exp;

    friend std::ostream &operator<<(std::ostream &o, const Stats &rhs) {
        return o << "[Stats] - Level: " << rhs.level << " Exp: " << rhs.exp << "\n";
    }

    friend class Worker;
};
