#pragma once

#include <iostream>
#include <vector>

class Account;

class Bank {
 public:
    Bank();

    int                   liquidity;
    std::vector<Account*> clientAccounts;

    friend std::ostream& operator<<(std::ostream& o, const Bank& bank);
};
