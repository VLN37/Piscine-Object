#pragma once

#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>

#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"
#include "utils.hpp"

class Workshop;

class Worker {
 public:
    Worker() : pos(Position()), stats(Stats()) {
        name = std::string("Worker ") + itoa(++id);
    }
    explicit Worker(std::string name) : pos(Position()), stats(Stats()), name(name) {
        ++id;
    }

    const std::string &get_name() const { return name; }

    void work(Workshop *shop) {
        std::cout << this << " works at workshop " << shop << "\n";
    }

    void equip(ATool *tool) {
        tool_iterator it = tools.find(tool->get_type());
        if (it != tools.end()) {
            std::cout << "should drop previous tool\n";
            unequip(it->second);
        }

        tools.insert(std::make_pair(tool->get_type(), tool));
        add_relation(tool, this);
        std::cout << *this << " equipped " << *tool << "\n";
    }

    void unequip(ATool *tool) {
        tool_iterator it = tools.find(tool->get_type());
        if (it == tools.end()) throw std::logic_error("tool is not equipped");
        tools.erase(it);
        remove_relation(tool);
    }

    bool has_tool(ToolType type) {
        std::cout << *this << " has " << ATool::tool_type_label(type) << ": "
                  << bool(tools.find(type) != tools.end()) << "\n";
        return tools.find(type) != tools.end();
    }

 private:
    typedef std::map<ToolType, ATool *>::iterator       tool_iterator;
    typedef std::map<ToolType, ATool *>::const_iterator tool_const_iterator;
    typedef std::map<ATool *, Worker *>::iterator       tool_work_iterator;
    typedef std::pair<tool_iterator, tool_iterator>     iterator_pair;

    Position    pos;
    Stats       stats;
    std::string name;

    static int                         id;
    std::map<ToolType, ATool *>        tools;
    static std::map<ATool *, Worker *> tool_work;

    static void add_relation(ATool *tool, Worker *worker) {
        tool_work_iterator it = tool_work.find(tool);
        if (it != tool_work.end()) {
            it->second->unequip(tool);
            std::cout << "Dropping tool from the other worker...\n";
        }
        tool_work.insert(std::make_pair(tool, worker));
        std::cout << "Tool relation added. Qty: " << tool_work.size() << "\n";
    }

    static void remove_relation(ATool *tool) {
        tool_work_iterator it = tool_work.find(tool);
        if (it != tool_work.end()) {
            tool_work.erase(it);
            std::cout << "Tool relation removed. Qty: " << tool_work.size() << "\n";
        }
    }

    friend std::ostream &operator<<(std::ostream &o, const Worker &rhs) {
        return o << "Level " << rhs.stats.get_level() << " " << rhs.name;
    }

    friend std::ostream &operator<<(std::ostream &o, Worker *rhs) {
        return o << "Level " << rhs->stats.get_level() << " " << rhs->name;
    }
};

int                         Worker::id        = 0;
std::map<ATool *, Worker *> Worker::tool_work = std::map<ATool *, Worker *>();
