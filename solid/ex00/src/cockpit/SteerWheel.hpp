#pragma once

#include <iostream>

#include "Dae.hpp"

class SteerWheel {
 public:
    SteerWheel() : dae(NULL) {}
    explicit SteerWheel(Dae *dae) : dae(dae) {}

    void setDae(Dae *dae) { this->dae = dae; }

    void turn(float p_angle) {
        std::cout << "using " << dae << " to turn " << p_angle << " angles" << "\n";
        dae->use(p_angle);
    }

 private:
    Dae *dae;
};
