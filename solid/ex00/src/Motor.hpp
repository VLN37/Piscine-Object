#pragma once

#include <iostream>

#include "Crankshaft.hpp"
#include "ExplosionChamber.hpp"
#include "Injector.hpp"

class Transmission;

class Motor {
 public:
    explicit Motor(Transmission *transmission)
        : started(false),
          shaft(Crankshaft(transmission)),
          chamber(ExplosionChamber(&shaft)),
          injector(Injector(&chamber)) {}

    ALinkablePart *getInjector() { return &injector; }
    void           connectToTransmission(Transmission *transmission) {
        std::cout << "connecting to transmission\n";
        shaft.connectToTransmission(transmission);
    }
    void start_engines() { started = true; }

 private:
    bool             started;
    Crankshaft       shaft;
    ExplosionChamber chamber;
    Injector         injector;
};
