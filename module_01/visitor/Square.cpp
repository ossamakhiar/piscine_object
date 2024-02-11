#include "Square.hpp"

void    Square::accept(Visitor *v)
{
    v->visit(this);
}

Square::Square(/* args */)
{
    std::cout << "Square C'Tor\n";
}

Square::~Square()
{
    std::cout << "Square D'Tor\n";
}
