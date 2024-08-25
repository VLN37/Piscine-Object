#pragma once

#include <iostream>
#include <vector>

#include "Vector2.hpp"

class Graph {
 public:
    Graph();

 private:
    std::size_t          size;
    std::vector<Vector2> points;

    friend std::ostream& operator<<(std::ostream& o, const Graph& graph);
};
