#pragma once

#include <iostream>

#include "ALinkablePart.hpp"

class Pedal {
 public:
    void setTarget(ALinkablePart *part) { this->part = part; }
    void use(float p_pression) {
        std::cout << "applying " << p_pression << " pressure to" << part << "\n";
    }

 private:
    ALinkablePart *part;
};
