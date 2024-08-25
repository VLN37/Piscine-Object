#include "Account.hpp"

#include <iostream>
#include <vector>

Account::Account() : id(-1), value(0) {}

std::ostream& operator<<(std::ostream& p_os, const Account& acc) {
    p_os << "[" << acc.id << "] - [" << acc.value << "]";
    return (p_os);
}
