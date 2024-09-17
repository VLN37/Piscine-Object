#include <iostream>

#include "car.hpp"

int main(void) {
    Car car(4);
    car.start();
    car.accelerate(50);
    car.shift_gears_up();
    car.shift_gears_up();
    car.apply_force_on_breaks(50);
    car.shift_gears_down();
    car.turn_wheel(35);
    car.apply_emergency_breaks();
}
