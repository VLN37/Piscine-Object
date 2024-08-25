#pragma once

#include <iostream>
#include <map>
#include <vector>

class Account;

#define BANK_LIQUIDITY "Not enough liquidity to provide loan\n"
#define BANK_ACCOUNT_NOT_FOUND "This account does not exist\n"
#define BANK_BALANCE_INSUFFICIENT "Not enough funds in account for withdrawal\n"

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

    class Exception : public std::exception {
     public:
        virtual const char* what() const throw();

     private:
        const char* msg;

        Exception();
        explicit Exception(const char* msg);

        friend class Bank;
    };

 private:
    typedef std::map<int, Account> AccountMap;

    float      liquidity;
    AccountMap accounts;
    int        sequence;

    friend std::ostream& operator<<(std::ostream& o, const Bank& bank);
};
