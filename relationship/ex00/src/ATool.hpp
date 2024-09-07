#pragma once

#include <map>
#include <utility>

enum ToolType { TOOL, SHOVEL, HAMMER };

class ATool {
 public:
    ATool() : numberOfUses(0), type(TOOL), id(++ATool::sequence) {
        _refCount.insert(std::make_pair(id, this));
    }

    virtual ~ATool() {
        std::cout << "ATool destructor called\n";
        _refCount.erase(this->id);
    }

    virtual void       use() = 0;
    bool               is_broken() const { return numberOfUses == 0; }
    const ToolType    &get_type() const { return type; }
    static void        debug() { std::cout << _refCount.size() << "\n"; }
    static const char *tool_type_label(ToolType type) {
        switch (type) {
            case TOOL:
                return "tool";
            case SHOVEL:
                return "shovel";
            case HAMMER:
                return "hammer";
        }
    }

 protected:
    int      numberOfUses;
    ToolType type;

    const char *tool_type_label() const { return tool_type_label(type); }

 private:
    static int sequence;
    int        id;

    static std::map<int, ATool *> _refCount;
    friend std::ostream          &operator<<(std::ostream &o, const ATool &rhs) {
        return rhs.output(o);
    }

    virtual std::ostream &output(std::ostream &o) const {
        return o << tool_type_label() << " with " << numberOfUses << " uses";
    }
};

int                    ATool::sequence  = 0;
std::map<int, ATool *> ATool::_refCount = std::map<int, ATool *>();
