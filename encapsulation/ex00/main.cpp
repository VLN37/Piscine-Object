#include <cassert>
#include <cstring>

#include "Account.hpp"
#include "Bank.hpp"

#define EXPECTS_THROW false

int main(void) {
    Bank bank = Bank();

    bank.create_account();
    bank.create_account(100);

    assert(bank.audit_liquidity() == 5);

    try {
        bank.withdraw(3, 50);
        assert(EXPECTS_THROW == true);
    } catch (Bank::Exception& e) {
        assert(strcmp(e.what(), BANK_ACCOUNT_NOT_FOUND) == 0);
    }

    std::cout << "Bank : " << std::endl;
    std::cout << bank << std::endl;

    return 0;
}
