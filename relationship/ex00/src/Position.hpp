#pragma once

class Position {
 public:
    Position() : x(0), y(0), z(0) {}
    Position(int x, int y, int z) : x(x), y(y), z(z) {}

    int x;
    int y;
    int z;

    friend std::ostream& operator<<(std::ostream& o, Position const& rhs) {
        return o << "[Position] - x: " << rhs.x << " y: " << rhs.y << " z: " << rhs.z
                 << "\n";
    }
};
