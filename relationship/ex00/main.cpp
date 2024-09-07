#include <iostream>

#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main(void) {
    Worker   bob("Bob");
    Worker   bro("Bro");
    Workshop grave("Consolation", GRAVEYARD);
    Workshop quarry("Stones", QUARRY);
    ATool   *shovel       = new Shovel;
    ATool   *hammer       = new Hammer;
    ATool   *spare_shovel = new Shovel;
    ATool   *spare_hammer = new Hammer;

    bob.equip(shovel);
    bob.equip(hammer);
    bro.equip(spare_hammer);
    bro.equip(spare_shovel);

    std::cout << bob << std::endl;
    std::cout << bro << std::endl;
    std::cout << "[[tool drop]]\n";
    bro.equip(shovel);
    try {
        grave.register_worker(&bob);
    } catch (std::invalid_argument &e) {
        std::cout << "Handling error: " << e.what() << std::endl;
    }

    std::cout << "[[re equip]]\n";
    bob.equip(shovel);
    bro.equip(spare_shovel);

    std::cout << bob << std::endl;
    std::cout << bro << std::endl;
    std::cout << *shovel << std::endl;
    std::cout << *hammer << std::endl;
    std::cout << grave << std::endl;
    std::cout << quarry << std::endl;

    quarry.register_worker(&bro);
    quarry.register_worker(&bob);
    grave.register_worker(&bro);
    grave.register_worker(&bob);

    std::cout << "[[remove employee]]\n";
    grave.unregister(&bob);
    std::cout << "[[Worker works]]\n";
    bro.work(&quarry);
    bro.work(&grave);
    bob.work(&quarry);

    std::cout << "[[Workshop works]]\n";
    grave.execute_work();

    std::cout << "[[tool equip]]\n";

    ATool::debug();
    delete shovel;
    delete hammer;
    delete spare_hammer;
    ATool::debug();
}
