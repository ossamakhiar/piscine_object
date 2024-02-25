#ifndef SHAPE_HPP
# define SHAPE_HPP

class   Shape
{
protected:

public:
    virtual double  calc_area() = 0;  
    virtual ~Shape() {};
};

#endif