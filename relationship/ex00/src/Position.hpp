#pragma once

class Position {
 public:
    Position() : x(0), y(0), z(0) {}
    Position(int x, int y, int z) : x(x), y(y), z(z) {}

    const int &get_x() const { return x; }
    const int &get_y() const { return y; }
    const int &get_z() const { return z; }

    friend std::ostream &operator<<(std::ostream &o, const Position &rhs) {
        return o << "[Pos] - x: " << rhs.x << " y: " << rhs.y << " z: " << rhs.z;
    }

 private:
    int x;
    int y;
    int z;

    friend class Worker;
};
