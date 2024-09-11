#pragma once

#include <iostream>

class DAE;

class SteerWheel {
 public:
    void turn(float p_angle) {
        std::cout << "using " << dae << " to turn " << p_angle << " angles" << "\n";
    }

 private:
    DAE *dae;
};
