#pragma once

#include "employee.hpp"

class TempWorker : public Employee {
 public:
    int executeWorkday() {
        timeSheet.insert(std::make_pair(time(0), 7));
        return 7;
    }
    void work(int hours) { timeSheet.insert(std::make_pair(time(0), hours)); }
    int  billableHours(int month, int year) {
        tm time;
        memset(&time, 0, sizeof(tm));
        time.tm_year          = year - 1900;
        time.tm_mon           = month - 1;
        time.tm_mday          = 1;
        time_t start_of_month = mktime(&time);
        time.tm_mon += 1;
        time_t end_of_month = mktime(&time);

        std::map<time_t, int>::iterator it;
        int                             hours = 0;

        for (it = timeSheet.begin(); it != timeSheet.end(); ++it) {
            if (it->first >= start_of_month && it->first < end_of_month)
                hours += it->second;
        }
        return hours;
    }

 protected:
    std::map<std::time_t, int> timeSheet;
};
