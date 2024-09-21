#pragma once

#include "employee.hpp"

class HourlyEmployee : public Employee {
 public:
    int executeWorkday() { return hourlyValue; }

 private:
    int hourlyValue;
};
