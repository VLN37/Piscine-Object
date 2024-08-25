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
    typedef int AccountId;

    Bank();

    AccountId create_account();
    AccountId create_account(float first_deposit);
    void      delete_account(AccountId id);
    float     withdraw(AccountId id, float value);
    void      deposit(AccountId id, float value);
    float     loan(float value);
    float     audit_liquidity() const;

    class Exception : public std::exception {
     public:
        virtual const char* what() const throw();

     private:
        const char* msg;

        Exception();
        explicit Exception(const char* msg);

        friend class Bank;
    };

    Account const& operator[](int idx);

 private:
    typedef std::map<AccountId, Account> AccountMap;

    float      liquidity;
    AccountMap accounts;
    AccountId  sequence;

    Account&             get_account(AccountId id);
    friend std::ostream& operator<<(std::ostream& o, const Bank& bank);
};
