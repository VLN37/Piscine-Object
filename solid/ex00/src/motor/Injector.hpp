#pragma once

#include <iostream>

#include "ALinkablePart.hpp"
#include "ExplosionChamber.hpp"

class Injector : public ALinkablePart {
 public:
    void execute(float p_pression) {
        std::cout << "executing " << p_pression << " pression on chamber\n";
        chamber->fill(p_pression);
    }

 private:
    ExplosionChamber *chamber;
};
