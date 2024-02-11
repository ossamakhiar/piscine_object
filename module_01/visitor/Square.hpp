#ifndef SQUARE_HPP
# define SQUARE_HPP

#include <iostream>
#include "Shape.hpp"
// #include "Visitor.hpp"

class Square : public Shape
{
private:
    /* data */
public:
    Square(/* args */);
    ~Square();

    int size() {
        return (5);
    }

    int area() {
        return (25);
    }

    void    accept(Visitor *v);
};

#include "Visitor.hpp"



#endif