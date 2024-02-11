#ifndef SHAPE_HPP
# define SHAPE_HPP

// #include "Visitor.hpp"
class Visitor;

class Shape
{
private:
    /* data */
public:

    virtual int size() = 0;
    virtual int area() = 0;

    virtual void    accept(Visitor *v) = 0;
};


#endif