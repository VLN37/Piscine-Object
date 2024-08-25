#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& o, Vector2 const& point) {
    return o << "Point(x:" << point.x << ", y:" << point.y << ")" << std::endl;
}
