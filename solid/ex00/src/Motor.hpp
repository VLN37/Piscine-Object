#pragma once

#include <iostream>

#include "Crankshaft.hpp"
#include "ExplosionChamber.hpp"
#include "Injector.hpp"

class Transmission;

class Motor {
 public:
    void connectToTransmission(Transmission *transmission) {
        std::cout << "connecting to transmission " << transmission << "\n";
        transmission->activate(0);
    }

    Injector         injector;
    ExplosionChamber chamber;
    Crankshaft       shaft;
};
