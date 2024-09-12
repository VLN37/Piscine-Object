#pragma once

#include <vector>

#include "Wheel.hpp"

class Transmission {
 public:
    void activate(float p_force) {
        std::cout << "Actvating transmission with " << p_force << " amount of force\n";
    }

 private:
    std::vector<Wheel> wheels;
};
