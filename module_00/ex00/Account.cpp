#include "Account.hpp"

Account::Account(int id, int value)
{
    this->id = id;
    this->value = value;
}

// Account::Account(const Account& other)
// {
    
// }

const int&  Account::get_value() const
{
    return (value);
}

const int&  Account::get_id() const
{
    return (id);
}

std::ostream& operator<< (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
}

/*
cpp, OOP, Constness]
Today, while being evaluated on the Piscine Object - Encapsulation assignment, a question arose.
The implementation details are as follows.
There are two classes, A and B. Class B is an inner class of A, and A can modify B with friend privileges.
B has an int type state (member variable? field?) called _id and _value, and does not provide modification of this in setter or other public methods.
B only has const getters for its own state.
Class A has a method that creates class B, assigns an ID to avoid duplication, stores the instance in itself, and returns the ID of the created B instance.
In B& A::operator[], you can have a reference to an instance of class B retrieved via ID.
In the case of the above implementation, can we say that the reference (B &) of the instance of class B returned by B &A::operator[] is equal to const B &?
When there is no public way to change the state by accessing an instance of a specific class from an external entity,
I wonder whether the instance of that class satisfies constness even if const is not explicitly added.

*/