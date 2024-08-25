#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank(): liquidity(0) {}

std::ostream& operator<<(std::ostream& o, const Bank& bank) {
    o << "Bank informations : " << std::endl;
    o << "Liquidity : " << bank.liquidity << std::endl;
    for (size_t i = 0; i < bank.clientAccounts.size(); ++i)
        o << *bank.clientAccounts[i] << std::endl;
    return (o);
}
