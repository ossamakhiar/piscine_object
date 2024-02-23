#ifndef SQUARE_HPP
# define SQUARE_HPP

class Square
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