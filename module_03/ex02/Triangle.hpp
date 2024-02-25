#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape
{
private:
    double  _base, _height;

public:
    Triangle(double base, double height) : _base(base), _height(height) {

    };

    ~Triangle() {};

    double  calc_area() {
        return (_height * _base) / 2;
    }
};


#endif