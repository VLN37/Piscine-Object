#pragma once

#include <iostream>

#include "Transmission.hpp"

class Crankshaft {
 public:
    void receiveForce(float p_volume) {
        std::cout << "Receiving " << p_volume << " amount of force\n";
        transmission->activate(p_volume);
    }

 private:
    Transmission *transmission;
};
