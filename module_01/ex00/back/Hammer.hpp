#ifndef HAMMER_HPP
# define HAMMER_HPP

#include "Tool.hpp"

class Hammer : Tool
{

public:
    Hammer() : Tool(0) {

    }

    ~Hammer() {

    }

    void    use() {
        numberOfUses++;

        std::cout << "Tak tak .. Hammer used by a worker\n";
    }
};


#endif