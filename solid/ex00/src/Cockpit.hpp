#pragma once

#include "GearLever.hpp"
#include "Pedal.hpp"
#include "SteerWheel.hpp"

class Cockpit {
 public:
    GearLever  lever;
    Pedal      pedal;
    SteerWheel steer_wheel;
};
