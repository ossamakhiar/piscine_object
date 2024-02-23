#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H

#include <iostream>


class SpeedControl {
private:
    int speed;

public:
    SpeedControl() : speed(0) {

    }

    ~SpeedControl() {

    }

    void accelerate(int increment) {
        speed += increment;
        std::cout << "Speed increased to " << speed << " km/h.\n";
    }

    void applyBrakes(int force)
    {
        speed -= force;
        if (speed < 0)
            speed = 0;
        std::cout << "Applied brakes with force: " << force << "." << std::endl;
    }

    void applyEmergencyBrakes()
    {
        std::cout << "Applied emergency brakes with maximum force." << std::endl;
        speed = 0;
    }
};

#endif