#pragma once

#include <iostream>

class Account {
 public:
    float get_value() const;
    int   get_id() const;

 private:
    Account();

    int   id;
    float value;

    explicit Account(int id);
    Account(int id, float first_deposit);

    friend std::ostream& operator<<(std::ostream& o, const Account& acc);
    friend class Bank;
};
