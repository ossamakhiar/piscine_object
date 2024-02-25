/***********************************/
/** Single Responsibilty Priciple **/
/***********************************/

#include "Car.hpp"


int main(void)
{
    Car car;

    car.start();
    car.accelerate(50);
    car.shift_gears_up();
    car.accelerate(20);
    car.shift_gears_up();
    car.apply_force_on_brakes(15);
    car.shift_gears_down();
    car.apply_emergency_brakes();
    car.stop();
    return (0);
}