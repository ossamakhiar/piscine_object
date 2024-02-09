#ifndef HAMMER_HPP
# define HAMMER_HPP

#include "Tool.hpp"

class Hammer : public Tool
{
private:
    Hammer(const Hammer&);
    Hammer& operator=(const Hammer&);

public:
    Hammer();
    ~Hammer();

    void    use();
};


#endif