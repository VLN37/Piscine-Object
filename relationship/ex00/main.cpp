#include <iostream>

#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main(void) {
    Worker   bobby("Bobby");
    Worker   broski("Broski");
    Workshop grave("Consolation", GRAVEYARD);
    Workshop quarry("Stones", QUARRY);
    ATool   *shovel       = new Shovel;
    ATool   *hammer       = new Hammer;
    ATool   *spare_shovel = new Shovel;
    ATool   *spare_hammer = new Hammer;

    std::cout << bobby << std::endl;
    std::cout << broski << std::endl;

    bobby.equip(shovel);
    bobby.equip(hammer);
    broski.equip(spare_shovel);
    broski.equip(spare_hammer);

    std::cout << "\n[[tool drop]]\n";
    broski.equip(shovel);
    try {
        grave.register_worker(&broski);
        grave.unregister_worker(&broski);
        grave.register_worker(&bobby);
    } catch (std::invalid_argument &e) {
        std::cout << "Handling error: " << e.what() << std::endl;
    }

    std::cout << "\n[[re equip]]\n";
    bobby.equip(shovel);
    broski.equip(spare_shovel);

    std::cout << bobby << std::endl;
    std::cout << broski << std::endl;
    std::cout << *shovel << std::endl;
    std::cout << *hammer << std::endl;
    std::cout << grave << std::endl;
    std::cout << quarry << std::endl;

    std::cout << "\n[[worker register]]\n";
    quarry.register_worker(&broski);
    quarry.register_worker(&bobby);
    grave.register_worker(&broski);
    grave.register_worker(&bobby);

    std::cout << "\n[[remove employee]]\n";
    grave.unregister_worker(&bobby);

    std::cout << "\n[[Worker works]]\n";
    broski.work(&quarry);
    broski.work(&grave);
    bobby.work(&quarry);

    std::cout << "\n[[Workshop works]]\n";
    grave.execute_work();
    quarry.execute_work();

    std::cout << "\n[[tool equip]]\n";

    delete shovel;
    delete hammer;
    delete spare_hammer;
    delete spare_shovel;
}
