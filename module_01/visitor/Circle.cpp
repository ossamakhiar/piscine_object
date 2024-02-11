#include "Circle.hpp"

void    Circle::accept(Visitor *v)
{
    v->visit(this);
}


Circle::Circle(/* args */)
{
    std::cout << "Circle C'Tor\n";
}

Circle::~Circle()
{
    std::cout << "Circle D'Tor\n";
}

