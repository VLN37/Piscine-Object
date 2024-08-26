#pragma once

#include <iostream>

class Vector2 {
 public:
    Vector2();
    Vector2(float x, float y);
    Vector2(Vector2 const& other);

    float x;
    float y;

    friend std::ostream& operator<<(std::ostream& o, Vector2 const& point);
    bool                 operator<(Vector2 const& rhs) const;
};
