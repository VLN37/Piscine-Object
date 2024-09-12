#pragma once

#include <vector>

#include "Wheel.hpp"

class Direction {
 public:
    void turn(float p_angle) { std::cout << "Turning " << p_angle << " radians\n"; }

 private:
    std::vector<Wheel> wheels;
};
