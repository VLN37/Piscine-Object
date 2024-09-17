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

    void start() {
        std::cout << "STARTING ENGINES\n";
        motor.connectToTransmission(&transmission);
        motor.start_engines();
    }
    void stop() {
        std::cout << "FULL STOP\n";
        brakes.emergency();
    }
    void accelerate(float p_pression) {
        std::cout << "ACCELERATING\n";
        motor.getInjector()->execute(p_pression);
    }
    void shift_gears_up() {
        std::cout << "GEAR UP\n";
        cockpit.shift_gears_up();
    }
    void shift_gears_down() {
        std::cout << "GEAR DOWN\n";
        cockpit.shift_gears_down();
    }
    void reverse() {
        std::cout << "ACTIVATING REVERSE GEAR\n";
        cockpit.reverse_gear();
    }
    void turn_wheel(float p_angle) {
        std::cout << "TURNING WHEELS\n";
        direction.turn(p_angle);
    }
    void straighten_wheels() {
        std::cout << "RESETTING WHEELS\n";
        direction.turn(0);
    }
    void apply_force_on_breaks(float p_pression) {
        std::cout << "REAR BRAKES\n";
        brakes.rearBrake(p_pression);
    }
    void apply_emergency_breaks() {
        std::cout << "EMERGENCY BRAKES\n";
        brakes.emergency();
    }

 private:
    std::vector<Wheel> *wheels;
    Direction           direction;
    BrakeController     brakes;
    Transmission        transmission;
    Electronics         electronics;
    Motor               motor;
    Cockpit             cockpit;
};
