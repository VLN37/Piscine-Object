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
    assert(bank.loan(5) == 5);
    assert(bank.audit_liquidity() == 0);

    bank.deposit(1, 50);
    assert(bank[1].get_value() == 47.5);
    bank.withdraw(1, 47.5);
    assert(bank[1].get_value() == 0);
    bank.delete_account(1);

    try {
        bank.delete_account(1);
        assert(EXPECTS_THROW == true);
    } catch (Bank::Exception &e) {
        assert(strcmp(e.what(), BANK_ACCOUNT_NOT_FOUND) == 0);
    }

    try {
        bank.withdraw(3, 50);
        assert(EXPECTS_THROW == true);
    } catch (Bank::Exception &e) {
        assert(strcmp(e.what(), BANK_ACCOUNT_NOT_FOUND) == 0);
    }

    try {
        bank.loan(5);
        assert(EXPECTS_THROW == true);
    } catch (Bank::Exception &e) {
        assert(strcmp(e.what(), BANK_LIQUIDITY) == 0);
    }

    std::cout << bank << std::endl;

    return 0;
}
