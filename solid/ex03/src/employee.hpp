#pragma once

class Employee {
 public:
    Employee() : hourlyValue(0) {}
    virtual int executeWorkday() { return hourlyValue; };

 private:
    int hourlyValue;

    friend class EmployeeManager;
};
