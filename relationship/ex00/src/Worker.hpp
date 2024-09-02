#pragma once

#include <iostream>

#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"

class Worker {
 public:
    Worker() : pos(Position()), stats(Statistic()) {}

    Position  pos;
    Statistic stats;

    friend std::ostream& operator<<(std::ostream& o, Worker const& rhs) {
        return o << "[Worker]\n" << "pos: " << rhs.pos << "stats: " << rhs.stats;
    }
};
