#pragma once

#include <iostream>
#include <vector>

#include "Gear.hpp"

class GearLever {
 public:
    GearLever() { GearLever(6); }
    explicit GearLever(int max_gears) : current_gear(0), max_gear(max_gears) {
        for (int i = 1; i <= max_gears; ++i) {
            gears.push_back(Gear(i));
        }
    }

    void change(int gear) {
        std::cout << "Changing gear to " << gear << "\n";
        current_gear = 0;
    }
    Gear *activeGear() { return &gears[current_gear]; }
    void  operator++(int) { operator++(); }
    void  operator--(int) { operator--(); }
    void  operator++() {
        if (activeGear()->get_demultiplier() == max_gear) {
            throw std::logic_error("Already on minimum gear");
        }
        ++current_gear;
        std::cout << "GearLever advances to gear " << current_gear << "\n";
    }
    void operator--() {
        if (activeGear()->get_demultiplier() == 0) {
            throw std::logic_error("Already on maximum gear");
        }
        --current_gear;
        std::cout << "GearLever returns to gear " << current_gear << "\n";
    }

 private:
    int               current_gear;
    int               max_gear;
    std::vector<Gear> gears;
};
