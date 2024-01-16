#include "Bank.hpp"


int main(void)
{
    int     id1, id2, id3;
    Bank    bank;

    id1 = bank.create_account(100);
    id2 = bank.create_account(205);
    id3 = bank.create_account(1999);

    const Account&  acc1 = bank[id1];

    std::cout << "Getting first account with id: " << acc1.get_id() << ", amount: " << acc1.get_value();
    std::cout << "\n";

    const Account& acc3 = bank[id3];

    std::cout << "Getting first account with id: " << acc3.get_id() << ", amount: " << acc3.get_value();
    std::cout << "\n";

    std::cout << "\n\e[1;32m<================>\e[0m\n\n"; 

    bank.deposit_money(id1, 1500);
    bank.deposit_money(id2, 500);
    bank.withdraw_money(id3, 599);

    std::cout << bank << "\n";
}