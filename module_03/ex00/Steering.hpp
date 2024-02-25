#ifndef STEERING_HPP
# define STEERING_HPP

#include <iostream>

class Steering
{

public:
    void    turn_wheel(int angle) {
        std::cout << "Turned wheels by " << angle << " degrees.\n";
    }

    void    straighten_wheels() {
        std::cout << "Wheels straightened.\n";
    }
};


#endif