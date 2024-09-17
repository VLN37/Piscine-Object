#pragma once

class Gear {
 public:
    Gear() : demultiplier(0) {}
    Gear(int demultiplier) : demultiplier(demultiplier) {}

    const int &get_demultiplier() { return demultiplier; }

 private:
    int demultiplier;
};
