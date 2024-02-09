#ifndef SHOVEL_HPP
# define SHOVEL_HPP

#include <iostream>
#include "Tool.hpp"

class Worker;

class   Shovel : public Tool
{
private:
	// ! Prohibited from copying...
	Shovel(const Shovel&);
	Shovel& operator=(const Shovel&);

public:
    Shovel();
    ~Shovel();

    void    use();

    // ? accessor
    int get_nou();
};


#endif