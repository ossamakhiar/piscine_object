#ifndef BANK_HPP
# define BANK_HPP

#include "Account.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <utility>

class Bank
{
private:
    int liquidity;
	// std::vector<Account *> clientAccounts;

    std::map<int, Account*>    accounts_db;

    static size_t   account_id;

public:
    Bank();
    Bank(int _liquidity);
    Bank(const Bank&);
    Bank& operator=(const Bank&);
    ~Bank();

    const int&  get_liquidity() const;
    void    set_liquidity(int);

    // ! Should I create GETTERS to accounts database??

    int     create_account(int intial_amount);
    void    close_account(int id);
    void    deposit_money(int id, int amount);
    void    withdraw_money(int id, int amount);
    void    give_loan(int id, int loan_amount);

    const Account& operator[](size_t);

    friend std::ostream& operator <<(std::ostream& p_os, const Bank& p_bank);
};



#endif