#pragma once

#include <string>

#include "shape.hpp"

class Circle : public Shape {
 public:
    Circle(float radius) : radius(radius) {}
    ~Circle() {};

    float       area() const { return radius * radius * 3.1415; }
    float       perimeter() const { return 2 * radius * 3.1415; }
    const char *shape_type() const { return "Circle"; }

 private:
    Circle() {}

    float radius;
};
