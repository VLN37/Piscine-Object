#include <iostream>

#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main(void) {
    std::cout << "Hello world\n";
    Worker   worker1;
    Worker   worker2;
    Workshop workshop1;
    Workshop workshop2;

    workshop1.register_worker(&worker1);
    workshop1.register_worker(&worker2);
    workshop2.register_worker(&worker2);

    workshop1.unregister(&worker1);
    worker2.work(&workshop2);

    workshop2.execute_work();

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
