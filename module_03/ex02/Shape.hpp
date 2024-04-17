#ifndef SHAPE_HPP
# define SHAPE_HPP

class   Shape
{
protected:
    // int x;

public:
    virtual double  calc_area() {
        return (0);
    }
    virtual double  calc_perimeter() {
        return (0);
    }
    virtual ~Shape() {};
};




#endif