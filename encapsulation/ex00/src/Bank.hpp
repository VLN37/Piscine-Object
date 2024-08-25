#pragma once

#include <iostream>
#include <map>
#include <vector>

class Account;

class Bank {
 public:
    Bank();

    int   create_account();
    int   create_account(float first_deposit);
    void  delete_account(int id);
    float withdraw(int id, float value);
    void  deposit(int id, float value);
    float loan(float value);
    float audit_liquidity() const;

 private:
    typedef std::map<int, Account> AccountMap;

    float      liquidity;
    AccountMap accounts;
    int        sequence;

    friend std::ostream& operator<<(std::ostream& o, const Bank& bank);
};
