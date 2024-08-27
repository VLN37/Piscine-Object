#pragma once

#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Vector2.hpp"

class Graph {
 public:
    Graph();
    explicit Graph(std::string filepath);

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
