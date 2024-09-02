#include <iostream>

#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"

int main(void) {
    std::cout << "Hello world\n";
    Worker worker1 = Worker();
    Worker worker2 = Worker();

    std::cout << worker1 << "\n";
    ATool *shovel = new Shovel;
    ATool *hammer = new Hammer;
    std::cout << *shovel;
    std::cout << *hammer;

    worker1.equip(shovel);
    std::cout << worker1;
    std::cout << worker2;
    worker2.equip(shovel);
    std::cout << worker1;
    std::cout << worker2;

    ATool::debug();
    delete shovel;
    delete hammer;
    ATool::debug();
}
