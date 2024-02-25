/*************************************/
/** Liskov's substitution principle **/
/*************************************/


//!!! NOT COMPLETED
#include "Shape.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <ostream>


std::ostream& operator<<(std::ostream& os, Shape& shape)
{
    std::cout << shape.calc_area();
    return (os);
}

// !by adhere to the Liskov Substitution principle it more likely to have a code that is extendable with changing the existing code 
// !hence make it easier to adhere to open closed principle
void    doSomething(Shape *shape)
{
    double area = shape->calc_area();

    // Some business logic goes here....
    (void)area;
}

int main(void)
{
    Shape   *circle = new Circle(1.9);
    Shape   *triangle = new Triangle(3, 2);
    Shape   *square = new Square(4);

    std::cout << "Circle Area: " << *circle << "\n";
    std::cout << "Triangle Area: " << *triangle << "\n";
    std::cout << "Square Area: " << *square << "\n";

    doSomething(new Circle(6.3)); // do something with a shape

    return (0);
}

// * Back to the last exercise Day 02 operator overloading