#pragma once

#include <iostream>
#include <map>

#include "ATool.hpp"

class Hammer : public ATool {
 public:
    Hammer() : ATool() {
        this->type         = HAMMER;
        this->numberOfUses = 3;
    }

    virtual ~Hammer() { std::cout << "Shovel destructor called\n"; }

    void use() {
        --numberOfUses;
        std::cout << "Using shovel\n";
    }

 private:
    virtual std::ostream &output(std::ostream &o) const {
        return o << "[Hammer] Number of uses: " << numberOfUses << "\n";
    }
};
