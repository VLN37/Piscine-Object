#include <unistd.h>

#include <cstring>
#include <ctime>
#include <iostream>

#include "employee.hpp"
#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main(void) {
    // Employee       *zumbis = new ContractEmployee[5];
    TempWorker       emp1;
    ContractEmployee emp2;
    Apprentice       emp3;
    Apprentice       emp4;
    EmployeeManager  manager;

    manager.addEmployee(&emp1);
    manager.executeWorkday();
    sleep(1);

    manager.addEmployee(&emp2);
    manager.executeWorkday();
    sleep(1);

    manager.addEmployee(&emp3);
    manager.addEmployee(&emp4);
    manager.executeWorkday();
    sleep(1);

    emp1.work(9);
    emp2.requestTimeOff(2);
    emp4.requestTimeOff(2);
    sleep(1);
    manager.previewCurrentPayroll();
}
