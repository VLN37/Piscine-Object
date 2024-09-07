#include "Bank.hpp"

#include <utility>

#include "Account.hpp"

Bank::AccountId Bank::sequence = 0;

Bank::Bank() : liquidity(1) {}

Bank::AccountId Bank::create_account() {
    ++this->sequence;
    this->accounts.insert(std::make_pair(sequence, Account(sequence)));
    return sequence;
}

Bank::AccountId Bank::create_account(float deposit) {
    ++this->sequence;
    this->accounts.insert(std::make_pair(sequence, Account(sequence, deposit * 0.95)));
    managed_assets += deposit * 0.95;
    free_assets += deposit * 0.05;
    return sequence;
}

void Bank::delete_account(AccountId id) {
    Account &acc = this->get_account(id);
    // all your base are belong to us
    this->free_assets += acc.value;
    this->accounts.erase(id);
}

float Bank::withdraw(AccountId id, float value) {
    Account &acc = this->get_account(id);
    if (acc.value < value) Bank::Exception(BANK_BALANCE_INSUFFICIENT);
    acc.value -= value;
    managed_assets -= value;
    return value;
}

void Bank::deposit(AccountId id, float value) {
    Account &acc = this->get_account(id);
    free_assets += value * 0.05;
    managed_assets += value * 0.95;
    acc.value += value * 0.95;
    liquidity = (free_assets + managed_assets) / managed_assets;
}

// We know where you live
float Bank::loan(float value) {
    if (value > free_assets) throw Bank::Exception(BANK_LIQUIDITY);
    free_assets -= value;
    return value;
}

float Bank::audit_liquidity() const {
    return (free_assets + managed_assets) / managed_assets;
}

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
    o << "[[BANK INFO]]" << std::endl;
    o << "managed assets: " << bank.managed_assets << std::endl;
    o << "own assets    : " << bank.free_assets << std::endl;
    o << "Liquidity     : " << bank.audit_liquidity() << std::endl;
    Bank::AccountMap::const_iterator it;
    for (it = bank.accounts.begin(); it != bank.accounts.end(); ++it)
        o << it->second << std::endl;
    return o;
}

Bank::Exception::Exception(const char *msg) : msg(msg) {}

const char *Bank::Exception::what(void) const throw() { return this->msg; }
