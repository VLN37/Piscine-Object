#pragma once

#include <algorithm>
#include <vector>

#include "Wheel.hpp"

class Transmission {
 public:
    explicit Transmission(std::vector<Wheel> *wheels) : wheels(wheels) {}
    void activate(float p_force) {
        std::cout << "Transmission activates with " << p_force << " amount of force\n";
        std::vector<Wheel>::iterator it;
        for (it = wheels->begin(); it != wheels->end(); ++it)
            it->ExecuteRotation(p_force);
    }

 private:
    Transmission() : wheels(NULL) {}
    std::vector<Wheel> *wheels;
};
