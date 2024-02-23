#ifndef GEAR_LEVER_HPP
# define GEAR_LEVER_HPP

#include <iostream>

class   GearLever
{
private:
    int level;

public:
    GearLever() : level(0) {

    }

    ~GearLever() {

    }

    void    shift_gears_up() {
        level++;
        std::cout << "Shifted up to " << level << " gear.\n";
    }

    void    shift_gears_down() {
        level = level ? (level - 1) : 0;
        std::cout << "Shifted down to " << level << " gear.\n";
    }

    void    reverse() {
        std::cout << "Shifted to reverse gear." << std::endl;
    }
};

#endif