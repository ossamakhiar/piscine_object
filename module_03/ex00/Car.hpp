#ifndef CAR_HPP
# define CAR_HPP

#include "Engine.hpp"
#include "Steering.hpp"
#include "SpeedControl.hpp"
#include "GearLever.hpp"

/**
* @brief  The Car class serves the sole purpose of coordinating and providing a unified interface
        for controlling individual components (a Facade for complex subsystem), including the engine, transmission, steering, and brakes. This design adheres to 
        the Single Responsibility Principle by encapsulating the complexities of their interactions,
        promoting modularity and maintainability in the codebase.
*/
class Car
{
private:
	Engine			engine;
	GearLever		gear_lever;
	Steering		steering;
	SpeedControl	speed_control;

public:
	void	start() {
		engine.start();
	}

	void	stop() {
		engine.stop();
	}

	void	shift_gears_up() {
		gear_lever.gear_lever();
	}

	void	shift_gears_down() {
		gear_lever.shift_gears_down();
	}

	void	reverse() {
		gear_lever.reverse();
	}

	void	turn_wheel(int angle) {
		steering.turn_wheel(angel);
	}

	void	straighten_wheels() {
		steering.straighten_wheels();
	}

	void	accelerate(int increment) {
		speed_control.accelerate(increment);
	}

	void	apply_force_on_brakes(int force) {
		speed_control.apply_force_on_brakes(force);
	}

	void	apply_emergency_brakes() {
		speed_control.apply_emergency_brakes();
	}
};



#endif