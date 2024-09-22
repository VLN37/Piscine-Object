#pragma once

#include <cstring>
#include <ctime>
#include <iostream>
#include <map>

class Employee {
 public:
    Employee() : hourlyValue(10), id(++sequence) {}
    virtual int executeWorkday()                   = 0;
    virtual int billableHours(int month, int year) = 0;
    int         billableHoursLastMonth() {
        time_t now = time(0);
        tm    *t   = localtime(&now);

        t->tm_mon -= 1;
        mktime(t);
        return billableHours(t->tm_mon + 1, t->tm_year + 1900);
    };

    static int sequence;
    static int workDays(int month, int year, time_t start) {
        tm time;

        std::memset(&time, 0, sizeof(tm));
        time.tm_year = year - 1900;
        time.tm_mon  = month - 1;
        time.tm_mday = 1;
        time_t t     = mktime(&time);

        time_t now = std::time(0);
        std::localtime(&now);
        time_t tomorrow = now + (60 * 60 * 24);
        int    qty      = 0;
        while (time.tm_mon == month - 1) {
            if (t >= start && t < tomorrow) ++qty;
            time.tm_mday += 1;
            t = mktime(&time);
        }
        return qty;
    }

 protected:
    int hourlyValue;

 private:
    int id;

    friend class EmployeeManager;
};

int Employee::sequence = 0;
