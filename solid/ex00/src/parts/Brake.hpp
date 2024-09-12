#pragma once

#include "ALinkablePart.hpp"
#include "Wheel.hpp"

class Brake : public ALinkablePart {
 public:
    void execute(float p_force) {
        std::cout << "Applying " << p_force << " amount of force on wheel\n";
        wheel->ExecuteRotation(p_force * -1);
    }

 private:
    Wheel *wheel;
};
