#pragma once

#include <iostream>

class Account {
 public:
    float const& get_value() const;
    int const&   get_id() const;

 private:
    int   id;
    float value;

    Account();
    explicit Account(int id);
    Account(int id, float first_deposit);

    friend std::ostream& operator<<(std::ostream& o, const Account& acc);
    friend class Bank;
};
