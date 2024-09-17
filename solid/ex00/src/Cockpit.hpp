#pragma once

#include "GearLever.hpp"
#include "Pedal.hpp"
#include "SteerWheel.hpp"

class Cockpit {
 public:
    explicit Cockpit(int max_gear) : lever(GearLever(max_gear)) {}

    void connectInjector(ALinkablePart *injector) { throttle.setTarget(injector); }
    void connectBrakes(ALinkablePart *brakes) { brake.setTarget(brakes); }
    void connectDae(Dae *dae) { steer_wheel.setDae(dae); }
    void shift_gears_up() { lever++; }
    void shift_gears_down() { lever--; }
    void reverse_gear() { lever.change(0); }

 private:
    Cockpit() {}

    GearLever  lever;
    Pedal      throttle;
    Pedal      brake;
    SteerWheel steer_wheel;
};
