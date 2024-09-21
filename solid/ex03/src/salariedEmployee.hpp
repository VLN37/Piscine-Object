#pragma once

#include "employee.hpp"

class ContractEmployee : public Employee {
 public:
    int executeWorkday() { return hourlyValue; }

 private:
    int hourlyValue;
};

class Apprentice : public Employee {
 public:
    int executeWorkday() { return hourlyValue; }

 private:
    int hourlyValue;
};
