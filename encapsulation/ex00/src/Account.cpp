#include "Account.hpp"

#include <iostream>
#include <vector>

Account::Account() : id(-1), value(0) {}

Account::Account(int id) : id(id), value(0) {}

Account::Account(int id, float first_deposit) : id(id), value(first_deposit) {}

float const& Account::get_value() const { return this->value; }

int const& Account::get_id() const { return this->id; }

std::ostream& operator<<(std::ostream& o, const Account& acc) {
    o << "[" << acc.id << "] - [" << acc.value << "]";
    return o;
}
