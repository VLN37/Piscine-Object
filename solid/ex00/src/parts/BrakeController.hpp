#pragma once

#include <iostream>
#include <vector>

#include "ALinkablePart.hpp"
#include "Brake.hpp"

class BrakeController : public ALinkablePart {
 public:
    explicit BrakeController(int wheel_qty) { brakes.resize(wheel_qty); }

    ALinkablePart *getPart() { return this; }
    void           execute(float p_pression) {
        std::cout << "Executing " << p_pression
                  << " amount of pression to all brakes\n";
        for (auto it = brakes.begin(); it != brakes.end(); ++it)
            it->execute(p_pression);
    }

    void attachBreaks(std::vector<Wheel> *wheels) {
        auto it1 = brakes.begin();
        auto it2 = wheels->begin();

        for (; it1 != brakes.end(); ++it1, ++it2) {
            it1->attachWheel(&(*it2));
        }
    }

    void rearBrake(float p_pression) {
        std::size_t qty = brakes.size();
        brakes.at(qty - 1).execute(p_pression);
        if (qty > 1) brakes.at(qty - 2).execute(p_pression);
    }

    void emergency() { execute(1000); }

 private:
    BrakeController() {}

    std::vector<Brake> brakes;
};
