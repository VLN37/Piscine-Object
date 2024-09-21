#pragma once

#include "shape.hpp"

class Triangle : public Shape {
 public:
    Triangle(float side) : side(side) {}
    ~Triangle() {};

    float       area() const { return 0.5 * side * side * 0.866025; }
    float       perimeter() const { return side * 3; }
    const char *shape_type() const { return "Triangle"; }

 private:
    Triangle() {}

    float side;
};
