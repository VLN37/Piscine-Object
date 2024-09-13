#pragma once

#include <iostream>

#include "Crankshaft.hpp"
#include "ExplosionChamber.hpp"
#include "Injector.hpp"

class Transmission;

class Motor {
 public:
    explicit Motor(Transmission *transmission)
        : shaft(Crankshaft(transmission)),
          chamber(ExplosionChamber(&shaft)),
          injector(Injector(&chamber)) {}

    ALinkablePart *getInjector() { return &injector; }
    void           connectToTransmission(Transmission *transmission) {
        std::cout << "connecting to transmission " << transmission << "\n";
        shaft.connectToTransmission(transmission);
    }

 private:
    Crankshaft       shaft;
    ExplosionChamber chamber;
    Injector         injector;
};
