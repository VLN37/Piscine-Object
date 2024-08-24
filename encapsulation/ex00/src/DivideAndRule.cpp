#include <iostream>
#include <vector>
#include "DivideAndRule.hpp"

Account::Account(): id(-1), value(0) {}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account) {
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
}

Bank::Bank(): liquidity(0) {}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
    for (size_t i = 0; i < p_bank.clientAccounts.size(); ++i)
        p_os << *p_bank.clientAccounts[i] << std::endl;
    return (p_os);
}
