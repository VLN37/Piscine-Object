#pragma once

#include <iostream>
#include <vector>

#include "Gear.hpp"

class GearLever {
 public:
    GearLever() { gears.resize(6); }
    explicit GearLever(int max_gears) { gears.resize(max_gears); }

    void  change() { std::cout << "Changing gear\n"; }
    Gear *activeGear() { return &gears.front(); }

 private:
    std::vector<Gear> gears;
};
