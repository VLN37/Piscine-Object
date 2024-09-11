#pragma once

#include <iostream>

#include "Crankshaft.hpp"

class ExplosionChamber {
 public:
    void fill(float p_volume) {
        std::cout << "filling crakshaft with " << p_volume << " volume\n";
        crankshaft->receiveForce(p_volume);
    }

 private:
    Crankshaft *crankshaft;
};
