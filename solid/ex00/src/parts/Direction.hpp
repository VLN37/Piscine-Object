#pragma once

#include <vector>

#include "Wheel.hpp"

class Direction {
 public:
    explicit Direction(std::vector<Wheel> *wheels) : wheels(wheels) {}

    void turn(float p_angle) {
        std::cout << "Turning " << p_angle << " radians\n";
        std::vector<Wheel>::iterator it;
        for (it = wheels->begin(); it != wheels->end(); ++it) {
            it->ExecuteRotation(p_angle);
        }
    }

 private:
    Direction() : wheels(NULL) {}
    std::vector<Wheel> *wheels;
};
