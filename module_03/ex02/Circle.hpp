#ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include "Shape.hpp"
#include <cmath>

class Circle : public Shape
{
private:
    double  radius;
public:
    Circle(double   r) : radius(r) {

    };

    ~Circle() {};

    double  calc_area() {
        return (M_PI * radius * radius);
    }
};


#endif