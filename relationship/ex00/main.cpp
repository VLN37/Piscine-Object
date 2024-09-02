#include <iostream>

#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"

int main(void) {
    std::cout << "Hello world\n";
    Worker worker = Worker();

    std::cout << worker << "\n";
    ATool *shovel = new Shovel;
    ATool *hammer = new Hammer;
    std::cout << *shovel;
    std::cout << *hammer;

    ATool::debug();
    delete shovel;
    delete hammer;
    ATool::debug();
}
