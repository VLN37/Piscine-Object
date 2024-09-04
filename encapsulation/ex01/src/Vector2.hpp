#pragma once

#include <iostream>

class Graph;

class Vector2 {
 public:
    Vector2();
    Vector2(float x, float y);
    Vector2(const Vector2 &other);

    float get_x() const;
    float get_y() const;

 private:
    float x;
    float y;

    friend std::ostream &operator<<(std::ostream &o, const Vector2 &point);
    bool                 operator<(const Vector2 &rhs) const;
};
