#pragma once

#include <algorithm>
#include <iomanip>
#include <set>

#include "employee.hpp"

class EmployeeManager {
 public:
    void addEmployee(Employee *emp) { employees.insert(emp); }
    void removeEmployee(Employee *emp) { employees.erase(emp); }
    void executeWorkday() {
        std::set<Employee *>::iterator it = employees.begin();
        for (; it != employees.end(); ++it) {
            (*it)->executeWorkday();
        }
    }
    void calculatePayroll() {
        std::set<Employee *>::iterator it;

        time_t now = time(0);
        tm    *t   = localtime(&now);

        t->tm_mon -= 1;
        mktime(t);
        std::cout << "# PAYROLL\n";
        for (it = employees.begin(); it != employees.end(); ++it) {
            int hours = (*it)->billableHours(t->tm_mon + 1, t->tm_year + 1900);
            std::cout << std::setw(8);
            std::cout << "Employee " << (*it)->id;
            std::cout << " - ";
            std::cout << std::setw(8);
            std::cout << "Salary " << hours * (*it)->hourlyValue << "\n";
        }
    }
    void previewCurrentPayroll() {
        std::set<Employee *>::iterator it;

        time_t now = time(0);
        tm    *t   = localtime(&now);

        mktime(t);
        std::cout << "# PAYROLL\n";
        for (it = employees.begin(); it != employees.end(); ++it) {
            int hours = (*it)->billableHours(t->tm_mon + 1, t->tm_year + 1900);
            std::cout << std::setw(8);
            std::cout << "Employee " << (*it)->id;
            std::cout << " - ";
            std::cout << std::setw(8);
            std::cout << "Salary " << hours * (*it)->hourlyValue << "\n";
        }
    }

 private:
    std::set<Employee *> employees;
};
