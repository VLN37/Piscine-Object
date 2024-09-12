#pragma once

#include <iostream>

class Wheel {
 public:
    void ExecuteRotation(float p_force) {
        std::cout << "Executing rotation with " << p_force << " amount of force\n";
    }
};
