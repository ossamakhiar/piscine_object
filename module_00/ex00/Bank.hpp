#ifndef BANK_HPP
# define BANK_HPP

#include "Account.hpp"
#include <vector>
#include <map>

class Bank
{
private:
    int liquidity;
	// std::vector<Account *> clientAccounts;

    std::map<int, Account>    accounts_db;
    // Account a;

public:
    Bank();
    Bank(int _liquidity);

    const int&  get_liquidity() const;

    void    set_liquidity();

    int     create_account(int intial_amount);
    void    close_account(int id);
    void    deposit_money(int id, int amount);
    void    withdraw_money(int id, int amount);
    void    give_loan();
};


#endif