#ifndef DIVIDEANDRULE_HPP
# define DIVIDEANDRULE_HPP

#include "MyRuntimeError.hpp"

class Bank;

class Account
{
private:
    int id;
	int value;

    Account(int id, int value);
    Account(const Account&);

    friend class Bank;
public:

    const int&  get_id() const;
    const int&  get_value() const;
};


#endif