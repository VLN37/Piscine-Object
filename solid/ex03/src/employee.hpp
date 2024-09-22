#pragma once

#include <cstring>
#include <ctime>
#include <iostream>
#include <map>

class DateUtil {
 public:
    tm     ref;
    time_t start_of_month;
    time_t end_of_month;
    time_t today;
    time_t tomorrow;

    DateUtil(int month, int year) {
        std::memset(&ref, 0, sizeof(tm));
        ref.tm_year = year - 1900;
        ref.tm_mon  = month - 1;
        ref.tm_mday = 1;

        tm backup;
        memcpy(&backup, &ref, sizeof(tm));
        start_of_month = mktime(&backup);
        backup.tm_mon += 1;
        end_of_month = mktime(&backup);

        time_t now   = std::time(0);
        tm    *tmp   = std::localtime(&now);
        tmp->tm_min  = 0;
        tmp->tm_sec  = 0;
        tmp->tm_hour = 0;

        today = mktime(tmp);
        tmp->tm_mday += 1;
        tomorrow = mktime(tmp);
    }

    static time_t today_date() {
        time_t now = std::time(0);
        tm    *t   = std::localtime(&now);
        t->tm_hour = 0;
        t->tm_min  = 0;
        t->tm_sec  = 0;
        return mktime(t);
    }
};

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

    static int workDays(int month, int year, time_t start) {
        DateUtil t(month, year);
        int      qty = 0;

        time_t iter = mktime(&t.ref);
        while (t.ref.tm_mon == month - 1) {
            if (iter >= t.start_of_month && iter < t.end_of_month)
                if (iter < t.tomorrow && iter >= start) ++qty;
            t.ref.tm_mday += 1;
            iter = mktime(&t.ref);
        }
        return qty;
    }

 protected:
    int hourlyValue;

 private:
    static int sequence;
    int        id;

    friend class EmployeeManager;
};

int Employee::sequence = 0;
