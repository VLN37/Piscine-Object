#pragma once

#include "Cockpit.hpp"

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

 private:
    Cockpit cockpit;
};
