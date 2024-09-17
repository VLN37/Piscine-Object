#pragma once

#include "Direction.hpp"

class Dae {
 public:
    explicit Dae(Direction *direction) : force(0), direction(direction) {}
    void use(float p_angle) {
        std::cout << "Using DAE at " << p_angle << " angle\n";
        direction->turn(p_angle);
    }
    const float &getForce() { return force; }

 private:
    float      force;
    Direction *direction;
};
