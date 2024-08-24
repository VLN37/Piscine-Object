#pragma once

#include <iostream>
#include <vector>

class Account {
 public:
    Account();

    int   id;
    float value;

    friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);
};

class Bank {
 public:
    Bank();

    int                   liquidity;
    std::vector<Account*> clientAccounts;

    friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
};
