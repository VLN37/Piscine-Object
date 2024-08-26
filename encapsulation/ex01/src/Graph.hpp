#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Vector2.hpp"

class Graph {
 public:
    Graph();

    void add_point(float x, float y);
    void add_point(Vector2 const& point);

    std::size_t          size;
    std::vector<Vector2> points;
    std::size_t          height;
    std::size_t          length;

 private:
    void update_size(float x, float y);

    friend std::ostream& operator<<(std::ostream& o, const Graph& graph);
};
