#pragma once

#include <iostream>

class Transmission;

class Crankshaft {
 public:
    void receiveForce(float p_volume) {
        std::cout << "Receiving " << p_volume << " amount of force\n";
        std::cout << transmission << "\n";
    }

 private:
    Transmission *transmission;
};
