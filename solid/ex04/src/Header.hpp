#pragma once

#include <cstring>
#include <ctime>
#include <string>

#include "iHeader.hpp"

class ConstHeader : public IHeader {
 public:
    ConstHeader() : header("[header]") {}
    ConstHeader(const char *header) : header(header) {}

    const char *output() { return header; }

 protected:
    const char *header;
};

class DateHeader : public IHeader {
    const char *output() {
        time_t   now         = std::time(0);
        std::tm *time_struct = std::localtime(&now);
        time_t   timestamp   = std::mktime(time_struct);
        char    *s           = std::ctime(&timestamp);
        s[strlen(s) - 1]     = ' ';
        return s;
    }
};
