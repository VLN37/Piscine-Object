#pragma once

#include <iostream>
#include <vector>

class Account {
 public:
    Account();

    int   id;
    float value;

    friend std::ostream& operator<<(std::ostream& o, const Account& acc);
};
