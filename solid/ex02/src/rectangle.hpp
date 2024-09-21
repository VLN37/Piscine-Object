#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
 public:
    Rectangle(float x, float y) : x(x), y(y) {}
    ~Rectangle() {};

    float       area() const { return x * y; }
    float       perimeter() const { return (x * 2) + (y * 2); }
    const char *shape_type() const { return "Rectangle"; }

 private:
    Rectangle() {}

    float x;
    float y;
};
