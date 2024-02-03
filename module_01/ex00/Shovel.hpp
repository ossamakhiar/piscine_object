#ifndef SHOVEL_HPP
# define SHOVEL_HPP

#include <iostream>

class   Shovel
{
private:
    int numberOfUses;

public:
    Shovel();
    ~Shovel();

    void    use();

    // ? accessor
    int get_nou();
};

#endif