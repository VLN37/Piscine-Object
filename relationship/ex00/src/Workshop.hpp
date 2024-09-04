#pragma once

#include <iostream>
#include <map>
#include <set>
#include <utility>

#include "Worker.hpp"

enum WorkshopType { CEMETERY, QUARRY };

class Workshop {
 public:
    Workshop() {}

    void register_worker(Worker *worker) { add_relation(this, worker); }
    void unregister(Worker *worker) { remove_relation(this, worker); }
    void execute_work() { _execute_work(this); }

    static std::set<const Workshop *> find_workshops(Worker *worker) {
        std::set<const Workshop *> res;
        worker_map_iterator        it;

        for (it = employees.begin(); it != employees.end(); ++it)
            if (it->second == worker) res.insert(it->first);
        return res;
    }

 private:
    typedef std::multimap<Workshop *, Worker *>                 WorkerMap;
    typedef std::multimap<Workshop *, Worker *>::iterator       worker_map_iterator;
    typedef std::multimap<Workshop *, Worker *>::const_iterator worker_map_c_iterator;
    typedef std::pair<worker_map_iterator, worker_map_iterator> iterator_pair;

    static WorkerMap employees;

    static void add_relation(Workshop *shop, Worker *worker) {
        employees.insert(std::make_pair(shop, worker));
    }

    static void remove_relation(Workshop *shop, Worker *worker) {
        iterator_pair       pair = employees.equal_range(shop);
        worker_map_iterator it   = pair.first;
        worker_map_iterator ite  = pair.second;

        std::cout << "[[remove employee]]\n";
        for (; it != ite; ++it) {
            std::cout << "first: " << it->first << " second: " << it->second << "\n";
            if (it->second == worker) {
                std::cout << "worker found\n";
                employees.erase(it);
            }
        }
    }

    static void _execute_work(Workshop *shop) {
        worker_map_iterator it;
        for (it = employees.find(shop); it != employees.end(); ++it) {
            it->second->work(shop);
        }
    }

    friend std::ostream &operator<<(std::ostream &o, const Workshop &rhs) {
        (void)rhs;
        return o << "workshop ptr at " << "PLACEHOLDER NAME" << "\n";
    }

    friend std::ostream &operator<<(std::ostream &o, Workshop *rhs) {
        (void)rhs;
        return o << "workshop ptr at " << "PLACEHOLDER NAME" << "\n";
    }
};

Workshop::WorkerMap Workshop::employees = Workshop::WorkerMap();
