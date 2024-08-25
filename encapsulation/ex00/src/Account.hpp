#pragma once

#include <iostream>

class Account {
 private:
    int   id;
    float value;

    Account();
    explicit Account(int id);
    Account(int id, float first_deposit);

    float get_value() const;
    int   get_id() const;

    friend std::ostream& operator<<(std::ostream& o, const Account& acc);
    friend class Bank;
};
