#pragma once

#include <vector>

#include "BrakeController.hpp"
#include "Cockpit.hpp"
#include "Electronics.hpp"
#include "Motor.hpp"
#include "Transmission.hpp"

class Car {
 public:
    explicit Car(int wheel_qty)
        : wheels(new std::vector<Wheel>()),
          direction(wheels),
          brakes(wheel_qty),
          transmission(wheels),
          electronics(&direction),
          motor(&transmission),
          cockpit(6) {
        wheels->resize(wheel_qty);
        cockpit.connectBrakes(brakes.getPart());
        cockpit.connectInjector(motor.getInjector());
        cockpit.connectDae(electronics.get_dae());
    }
    ~Car() { delete wheels; }

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
    std::vector<Wheel> *wheels;
    Direction           direction;
    BrakeController     brakes;
    Transmission        transmission;
    Electronics         electronics;
    Motor               motor;
    Cockpit             cockpit;
};
