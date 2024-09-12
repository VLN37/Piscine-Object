#pragma once

#include "Direction.hpp"

class Dae {
 public:
    void  use(float p_angle) { std::cout << "Using DAE at " << p_angle << " angle\n"; }
    float force;
    Direction *direction;
};
