#pragma once

#include <iostream>

#include "Transmission.hpp"

class Crankshaft {
 public:
    Crankshaft() : transmission(NULL) {}
    explicit Crankshaft(Transmission *transmission) : transmission(transmission) {}

    void receiveForce(float p_volume) {
        std::cout << "Receiving " << p_volume << " amount of force\n";
        transmission->activate(p_volume);
    }
    void connectToTransmission(Transmission *transmission) {
        this->transmission = transmission;
    }

 private:
    Transmission *transmission;
};
