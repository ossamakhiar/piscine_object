#ifndef SQUARE_HPP
# define SQUARE_HPP

#include "Shape.hpp"

class Square : public Shape
{
private:
    double  side;

public:
    Square(double side_) : side(side_) {

    };

    ~Square() {};

    double  calc_area() {
        return (side * side);
    }
};


#endif