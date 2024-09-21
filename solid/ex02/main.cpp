#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main(void) {
    std::cout << Triangle(3) << std::endl;
    std::cout << Rectangle(3, 4) << std::endl;
    std::cout << Circle(2.5) << std::endl;
}
