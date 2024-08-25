#include <cassert>

#include "Account.hpp"
#include "Bank.hpp"

#define EXPECTS_THROW false

int main(void) {
    Bank bank = Bank();

    bank.create_account();
    bank.create_account(100);

    assert(bank.audit_liquidity() == 5);

    std::cout << " ----- " << std::endl;

    std::cout << "Bank : " << std::endl;
    std::cout << bank << std::endl;

    return 0;
}
