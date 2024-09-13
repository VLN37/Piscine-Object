#pragma once

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

#include "Worker.hpp"
#include "utils.hpp"

enum WorkshopType { GRAVEYARD, QUARRY };

class Workshop {
 public:
    std::string  name;
    WorkshopType type;

    Workshop(std::string name, WorkshopType t) : name(name), type(t) { ++id; }
    explicit Workshop(WorkshopType t)
        : name(std::string(type_label(t)) + itoa(++id)), type(t) {}

    void register_worker(Worker *worker) {
        const char *msg = "Worker does not have the required tool";
        if (!worker->has_tool(required_tool())) throw std::invalid_argument(msg);
        add_relation(this, worker);
    }

    void unregister_worker(Worker *worker) { remove_relation(this, worker); }
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
    static int       id;

    Workshop();

    ToolType required_tool() {
        switch (type) {
            case GRAVEYARD:
                return SHOVEL;
            case QUARRY:
                return HAMMER;
        }
    }

    const char *type_label() const { return type_label(this->type); }

    const char *type_label(WorkshopType t) const {
        switch (t) {
            case QUARRY:
                return "quarry";
            case GRAVEYARD:
                return "graveyard";
        }
    }

    static void add_relation(Workshop *shop, Worker *worker) {
        // std::cout << "add workshop relation" << shop << " " << worker << "\n";
        employees.insert(std::make_pair(shop, worker));
    }

    static void remove_relation(Workshop *shop, Worker *worker) {
        // std::cout << "rem workshop relation" << shop << " " << worker << "\n";
        iterator_pair       pair = employees.equal_range(shop);
        worker_map_iterator it   = pair.first;
        worker_map_iterator ite  = pair.second;

        for (; it != ite; ++it) {
            if (it->second == worker) {
                std::cout << it->second << " removed from " << it->first << "\n";
                return employees.erase(it);
            }
        }
    }

    static void _execute_work(Workshop *shop) {
        iterator_pair       pair = employees.equal_range(shop);
        worker_map_iterator it   = pair.first;
        worker_map_iterator ite  = pair.second;

        for (it = employees.find(shop); it != ite; ++it) {
            it->second->work(shop);
        }
    }

    friend std::ostream &operator<<(std::ostream &o, const Workshop &rhs) {
        return o << rhs.name << " " << rhs.type_label();
    }

    friend std::ostream &operator<<(std::ostream &o, Workshop *rhs) {
        return o << rhs->name << " " << rhs->type_label();
    }

    static void debug_employees() {
        worker_map_iterator it = employees.begin();

        std::cout << "[[debug]]\n";
        for (it = employees.begin(); it != employees.end(); ++it) {
            std::cout << it->first << " " << it->second << "\n";
        }
        std::cout << "[[end debug]]\n";
    }
};

Workshop::WorkerMap Workshop::employees = Workshop::WorkerMap();
int                 Workshop::id        = 0;
