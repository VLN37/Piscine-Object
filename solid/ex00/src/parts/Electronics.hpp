#pragma once

#include "Dae.hpp"

class Electronics {
 public:
    explicit Electronics(Direction *direction) : dae(Dae(direction)) {}

    Dae *get_dae() { return &dae; }

 private:
    Dae dae;
};
