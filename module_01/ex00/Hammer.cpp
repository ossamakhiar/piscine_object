#include "Hammer.hpp"


Hammer::Hammer()
{
    std::cout << "Hammer constructed\n";
}

Hammer::~Hammer()
{
    std::cout << "Hammer destructed\n";
    this->notify();
}

void    Hammer::use()
{
    this->numberOfUses++;

    std::cout << "Hammer used " << numberOfUses << " times\n";
}

