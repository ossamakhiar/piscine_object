#ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include <cmath>

class Circle
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