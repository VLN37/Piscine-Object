#pragma once

#include "BrakeController.hpp"
#include "Cockpit.hpp"
#include "Electronics.hpp"
#include "Motor.hpp"
#include "Transmission.hpp"

class Car {
 public:
    void start() {}
    void stop() {}
    void accelerate() {}
    void shift_gears_up() {}
    void shift_gears_down() {}
    void reverse() {}
    void turn_wheel() {}
    void straighten_wheels() {}
    void apply_force_on_breaks() {}
    void apply_emergency_breaks() {}

    BrakeController brakes;
    Transmission    transmission;
    Electronics     electronics;
    Cockpit         cockpit;
    Motor           motor;
};
