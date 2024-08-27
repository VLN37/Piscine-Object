#pragma once

#include <iostream>

class Graph;

class Vector2 {
 public:
    Vector2();
    Vector2(float x, float y);
    Vector2(Vector2 const& other);

    float get_x() const;
    float get_y() const;

 private:
    float x;
    float y;

    friend std::ostream& operator<<(std::ostream& o, Vector2 const& point);
    bool                 operator<(Vector2 const& rhs) const;
};
