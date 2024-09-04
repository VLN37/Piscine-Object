#include "Bank.hpp"

#include <utility>

#include "Account.hpp"

Bank::AccountId Bank::sequence = 0;

Bank::Bank() : liquidity(0) {}

Bank::AccountId Bank::create_account() {
    ++this->sequence;
    this->accounts.insert(std::make_pair(sequence, Account(sequence)));
    return sequence;
}

Bank::AccountId Bank::create_account(float deposit) {
    ++this->sequence;
    this->accounts.insert(std::make_pair(sequence, Account(sequence, deposit * 0.95)));
    this->liquidity += deposit * 0.05;
    return sequence;
}

void Bank::delete_account(AccountId id) {
    Account &acc = this->get_account(id);
    // all your base are belong to us
    this->liquidity += acc.value;
    this->accounts.erase(id);
}

float Bank::withdraw(AccountId id, float value) {
    Account &acc = this->get_account(id);
    if (acc.value < value) Bank::Exception(BANK_BALANCE_INSUFFICIENT);
    acc.value -= value;
    return value;
}

void Bank::deposit(AccountId id, float value) {
    Account &acc = this->get_account(id);
    this->liquidity += value * 0.05;
    acc.value += value * 0.95;
}

// We know where you live
float Bank::loan(float value) {
    if (value > this->liquidity) throw Bank::Exception(BANK_LIQUIDITY);
    this->liquidity -= value;
    return value;
}

const float &Bank::audit_liquidity() const { return this->liquidity; }

const Account &Bank::get_account(Bank::AccountId id) const {
    AccountMap::const_iterator it = this->accounts.find(id);
    if (it == this->accounts.end()) throw Bank::Exception(BANK_ACCOUNT_NOT_FOUND);
    return it->second;
}

Account &Bank::get_account(Bank::AccountId id) {
    AccountMap::iterator it = this->accounts.find(id);
    if (it == this->accounts.end()) throw Bank::Exception(BANK_ACCOUNT_NOT_FOUND);
    return it->second;
}

const Account &Bank::operator[](int idx) const { return this->get_account(idx); }

std::ostream &operator<<(std::ostream &o, const Bank &bank) {
    o << "Bank informations : " << std::endl;
    o << "Liquidity : " << bank.liquidity << std::endl;
    Bank::AccountMap::const_iterator it;
    for (it = bank.accounts.begin(); it != bank.accounts.end(); ++it)
        o << it->second << std::endl;
    return o;
}

Bank::Exception::Exception(const char *msg) : msg(msg) {}

const char *Bank::Exception::what(void) const throw() { return this->msg; }
