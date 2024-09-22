#pragma once

#include <map>
#include <utility>

#include "employee.hpp"

class ContractEmployee : public Employee {
 public:
    ContractEmployee() : contractStart(time(0)) {}
    int  executeWorkday() { return 7; }
    void requestTimeOff(int hours) { timeOff.insert(std::make_pair(time(0), hours)); }
    int  billableHours(int month, int year) {
        int days     = workDays(month, year, contractStart);
        int time_off = 0;

        tm time;
        memset(&time, 0, sizeof(tm));
        time.tm_year          = year - 1900;
        time.tm_mon           = month - 1;
        time.tm_mday          = 1;
        time_t start_of_month = mktime(&time);
        time.tm_mon += 1;
        time_t end_of_month = mktime(&time);

        std::map<std::time_t, int>::iterator it;
        for (it = timeOff.begin(); it != timeOff.end(); ++it) {
            if (it->first >= start_of_month && it->first < end_of_month)
                time_off += it->second;
        }
        return (days * 7) - time_off;
    }

 protected:
    std::map<std::time_t, int> timeOff;
    time_t                     contractStart;
};

class Apprentice : public ContractEmployee {
 public:
    int executeWorkday() {
        int worktime   = ContractEmployee::executeWorkday();
        int schooltime = 6;

        schoolTime.insert(std::make_pair(time(0), schooltime));
        return worktime / 2;
    }

    int billableHours(int month, int year) {
        int worktime = ContractEmployee::billableHours(month, year);

        tm time;
        memset(&time, 0, sizeof(tm));
        time.tm_year          = year - 1900;
        time.tm_mon           = month - 1;
        time.tm_mday          = 1;
        time_t start_of_month = mktime(&time);
        time.tm_mon += 1;
        time_t end_of_month = mktime(&time);

        int schooltime = 0;

        std::map<time_t, int>::iterator it;
        for (it = schoolTime.begin(); it != schoolTime.end(); ++it) {
            if (it->first >= start_of_month && it->first < end_of_month) {
                schooltime += it->second;
            }
        }
        return (worktime / 2) + (schooltime / 2);
    }

 protected:
    std::map<time_t, int> schoolTime;
};
