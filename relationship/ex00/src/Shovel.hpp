#pragma once

#include <iostream>
#include <map>

#include "ATool.hpp"

class Shovel : public ATool {
 public:
    Shovel() : ATool() {
        this->type         = SHOVEL;
        this->numberOfUses = 3;
    }

    virtual ~Shovel() { std::cout << "Shovel destructor called\n"; }

    void use() {
        --numberOfUses;
        std::cout << "Using shovel\n";
    }

 private:
    virtual std::ostream& output(std::ostream& o) const {
        return o << "[Shovel] Number of uses: " << numberOfUses << "\n";
    }
};
