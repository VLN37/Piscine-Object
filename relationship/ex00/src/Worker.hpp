#pragma once

#include <iomanip>
#include <iostream>
#include <map>
#include <utility>

#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"

class Worker {
 public:
    Worker() : pos(Position()), stats(Statistic()) {}

    Position  pos;
    Statistic stats;

    void equip(ATool* tool) {
        tool_iterator it = tools.find(tool->get_type());
        if (it != tools.end()) {
            std::cout << "should drop previous tool\n";
            drop(it->second);
        }

        tools.insert(std::make_pair(tool->get_type(), tool));
        add_relation(tool, this);
        std::cout << "Tool equipped\n";
    }

    void drop(ATool* tool) {
        tool_const_iterator it = tools.find(tool->get_type());
        if (it == tools.end()) throw std::logic_error("tool is not equipped");
        tools.erase(tool->get_type());
        remove_relation(tool);
    }

    friend std::ostream& operator<<(std::ostream& o, Worker const& rhs) {
        return o << "[Worker]\n"
                 << "    pos: " << rhs.pos << "    stats: " << rhs.stats << std::left
                 << std::setw(4) << "    tools: " << rhs.tools.size() << "\n";
    }

 private:
    typedef std::map<ToolType, ATool*>::iterator       tool_iterator;
    typedef std::map<ToolType, ATool*>::const_iterator tool_const_iterator;
    typedef std::map<ATool*, Worker*>::iterator        tool_work_iterator;

    std::map<ToolType, ATool*>       tools;
    static std::map<ATool*, Worker*> tool_work;

    static void add_relation(ATool* tool, Worker* worker) {
        tool_work_iterator it = tool_work.find(tool);
        if (it != tool_work.end()) {
            it->second->drop(tool);
            std::cout << "Dropping tool from the other worker...\n";
        }
        tool_work.insert(std::make_pair(tool, worker));
        std::cout << "Tool relation added. Qty: " << tool_work.size() << "\n";
    }
    static void remove_relation(ATool* tool) {
        if (tool_work.erase(tool)) {
            std::cout << "Tool relation removed. Qty: " << tool_work.size() << "\n";
        }
    }
};

std::map<ATool*, Worker*> Worker::tool_work = std::map<ATool*, Worker*>();
