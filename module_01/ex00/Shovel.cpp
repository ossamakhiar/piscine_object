#include "Shovel.hpp"

Shovel::Shovel() : numberOfUses(0)
{
    std::cout << "Shovel constructed\n";
}

Shovel::~Shovel()
{
    std::cout << "Shovel has destroied\n";
}

void    Shovel::use()
{
    numberOfUses++;

    std::cout << "Shovel has been used\n";
}

// ? accessor
int Shovel::get_nou()
{
    return (numberOfUses);
}