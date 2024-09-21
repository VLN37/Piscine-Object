#pragma once

#include <iomanip>
#include <iostream>

class Shape {
 public:
    virtual float       area() const       = 0;
    virtual float       perimeter() const  = 0;
    virtual const char *shape_type() const = 0;

    friend std::ostream &operator<<(std::ostream &o, const Shape &rhs) {
        o << std::setw(10) << "Shape: " << std::setw(10) << rhs.shape_type();
        o << std::setw(10) << " Area: " << std::setw(10) << rhs.area();
        o << std::setw(10) << " Perimeter: " << std::setw(10) << rhs.perimeter();
        return o;
    }
};
