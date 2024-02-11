#ifndef VISITOR_HPP
# define VISITOR_HPP

#include <iostream>
#include "Circle.hpp"
#include "Square.hpp"

class Visitor
{
private:
    /* data */
public:
    // Visitor();
    // ~Visitor();

    void    visit(Circle *circle)
    {
        std::cout << "Visiting circle\n";
    }

    void    visit(Square *square)
    {
        std::cout << "Visiting square\n";
    }

};



#endif