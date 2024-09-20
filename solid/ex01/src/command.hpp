#pragma once

#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class Command {
 public:
    Command() : id(++sequence), time(std::time(0)), client("Bro") {};
    virtual ~Command() {};

    virtual float get_total_price() const {
        float total = 0;

        std::map<std::string, size_t>::const_iterator it;
        for (it = articles.begin(); it != articles.end(); ++it)
            total += prices.find(it->first)->second * it->second;
        return total;
    }

    void order(std::string dish, size_t qty) {
        if (prices.find(dish) == prices.end())
            throw std::logic_error("dish does not exist");
        articles.insert(std::make_pair(dish, qty));
    }

 protected:
    size_t                        id;
    std::time_t                   time;
    std::string                   client;
    std::map<std::string, size_t> articles;

    friend std::ostream &operator<<(std::ostream &o, const Command &rhs) {
        o << std::left;
        o << "Command\n";
        o << std::setw(15) << "Id" << ": " << rhs.id << "\n";
        o << std::setw(15) << "Client" << ": " << rhs.client << "\n";
        o << std::setw(15) << "Time" << ": " << std::ctime(&rhs.time);
        o << std::setw(15) << "Total price" << ": " << rhs.get_total_price() << "\n";
        return o;
    }
    static const std::map<std::string, float> prices;

 private:
    static size_t sequence;

    static const std::map<std::string, float> init_prices() {
        std::map<std::string, float> prices;
        prices.insert(std::make_pair("burguer", 20));
        prices.insert(std::make_pair("fries", 10));
        prices.insert(std::make_pair("all_you_can_eat", 100));
        return prices;
    }
};

size_t                             Command::sequence = 0;
const std::map<std::string, float> Command::prices   = Command::init_prices();
