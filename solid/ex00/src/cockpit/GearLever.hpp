#pragma once

#include <iostream>
#include <vector>

#include "Gear.hpp"

class GearLever {
 public:
    void  change() { std::cout << "Changing gear\n"; }
    Gear *activeGear() { return &gears.front(); }

 private:
    std::vector<Gear> gears;
};
