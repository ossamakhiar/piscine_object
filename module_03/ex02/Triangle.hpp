#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

class Triangle : Shape
{
private:
    double  a, b, c, h;

public:
    Triangle(double a_, double b_, double c_, double h_) : a(a_), b(b_), c(c_), h(h_) {

    };

    ~Triangle() {};

    double  calc_area() {
        return (h * b) / 2;
    }
};


#endif