#pragma once

class Gear {
 public:
    Gear() : demultiplier(0) {}

    const int &get_demultiplier() { return demultiplier; }

 private:
    int demultiplier;
};
