#pragma once

#include <iostream>
#include <vector>

#include "Brake.hpp"

class BrakeController {
 public:
    void execute(float p_pression) {
        std::cout << "Executing " << p_pression
                  << " amount of pression to all brakes\n";
        std::vector<Brake>::iterator it;
        for (it = brakes.begin(); it != brakes.end(); ++it) it->execute(p_pression);
    }

 private:
    std::vector<Brake> brakes;
};
