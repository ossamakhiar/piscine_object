#include "Circle.hpp"
#include "Square.hpp"
#include "Visitor.hpp"

int main(void)
{
    Shape   *circle = new Circle();
    Shape   *square = new Square();

    Visitor *v = new Visitor();

    // v->visit(circle);
    // v->visit(square);

    circle->accept(v);
    square->accept(v);

    return (0);
}