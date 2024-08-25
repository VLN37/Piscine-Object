#include "Bank.hpp"

#include <utility>

#include "Account.hpp"

Bank::Bank() : liquidity(0), sequence(0) {}

int Bank::create_account() {
    ++this->sequence;
    this->accounts.insert(std::make_pair(sequence, Account(sequence)));
    return sequence;
}

int Bank::create_account(float deposit) {
    ++this->sequence;
    this->accounts.insert(std::make_pair(sequence, Account(sequence, deposit * 0.95)));
    this->liquidity += deposit * 0.05;
    return sequence;
}

void Bank::delete_account(int id) {
    AccountMap::iterator it = this->accounts.find(id);
    if (it == this->accounts.end()) throw std::exception();
    // all your base are belong to us
    this->liquidity += it->second.value;
    this->accounts.erase(id);
}

float Bank::withdraw(int id, float value) {
    AccountMap::iterator it = this->accounts.find(id);
    if (it == this->accounts.end()) throw std::exception();
    if (it->second.value < value) throw std::exception();
    it->second.value -= value;
    return value;
}

void Bank::deposit(int id, float value) {
    AccountMap::iterator it = this->accounts.find(id);
    if (it == this->accounts.end()) throw std::exception();
    this->liquidity += value * 0.05;
    it->second.value += value * 0.95;
}

// We know where you live
float Bank::loan(float value) {
    if (value > this->liquidity) throw std::exception();
    return value;
}

float Bank::audit_liquidity() const { return this->liquidity; }

std::ostream& operator<<(std::ostream& o, const Bank& bank) {
    o << "Bank informations : " << std::endl;
    o << "Liquidity : " << bank.liquidity << std::endl;
    Bank::AccountMap::const_iterator it;
    for (it = bank.accounts.begin(); it != bank.accounts.end(); ++it)
        o << it->second << std::endl;
    return o;
}
