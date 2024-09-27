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
        DateUtil t(month, year);
        int      hours = 0;

        for (auto it = timeSheet.begin(); it != timeSheet.end(); ++it) {
            if (it->first >= t.start_of_month && it->first < t.end_of_month)
                hours += it->second;
        }
        return hours;
    }

 protected:
    std::map<std::time_t, int> timeSheet;
};
