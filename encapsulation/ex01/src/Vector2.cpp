#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(Vector2 const& other) : x(other.x), y(other.y) {}

float Vector2::get_x() const { return this->x; }

float Vector2::get_y() const { return this->y; }

bool Vector2::operator<(Vector2 const& rhs) const {
    return this->y < rhs.y || this->x < rhs.x;
}

std::ostream& operator<<(std::ostream& o, Vector2 const& point) {
    return o << "Point(x:" << point.x << ", y:" << point.y << ")" << std::endl;
}
