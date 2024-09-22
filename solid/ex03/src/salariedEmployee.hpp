#pragma once

#include <map>
#include <utility>

#include "employee.hpp"

class ContractEmployee : public Employee {
 public:
    ContractEmployee() : contractStart() { contractStart = DateUtil::today_date(); }
    int  executeWorkday() { return 7; }
    void requestTimeOff(int hours) { timeOff.insert(std::make_pair(time(0), hours)); }
    int  billableHours(int month, int year) {
        int      days = workDays(month, year, contractStart);
        DateUtil t(month, year);
        int      time_off = 0;

        std::map<std::time_t, int>::iterator it;
        for (it = timeOff.begin(); it != timeOff.end(); ++it) {
            if (it->first >= t.start_of_month && it->first < t.end_of_month)
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
        DateUtil t(month, year);
        int      worktime = ContractEmployee::billableHours(month, year);

        int schooltime = 0;

        std::map<time_t, int>::iterator it;
        for (it = schoolTime.begin(); it != schoolTime.end(); ++it) {
            if (it->first >= t.start_of_month && it->first < t.end_of_month) {
                schooltime += it->second;
            }
        }
        return (worktime / 2) + (schooltime / 2);
    }

 protected:
    std::map<time_t, int> schoolTime;
};
