#ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include <iostream>
#include "Shape.hpp"

// #include "Visitor.hpp"

class Circle : public Shape
{
private:
    /* data */
public:
    Circle(/* args */);
    ~Circle();

    int size() {
        return (5);
    }

    int area() {
        return (80);
    }



    void    accept(Visitor *v);
};

#include "Visitor.hpp"


#endif