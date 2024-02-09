#include "Shovel.hpp"

Shovel::Shovel()
{
    std::cout << "Shovel constructed\n";
}

Shovel::~Shovel()
{
    std::cout << "Shovel has destroyed\n";
    this->notify();
    // notify();
}

void    Shovel::use()
{
    numberOfUses++;
    std::cout << "Shovel has been used " << numberOfUses << " times.\n";
}

// ? accessor
int Shovel::get_nou()
{
    return (numberOfUses);
}