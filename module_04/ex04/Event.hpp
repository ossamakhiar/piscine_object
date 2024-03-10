#ifndef EVENT_SUBJECT_HPP
# define EVENT_SUBJECT_HPP 

#include <algorithm>
#include "observer.hpp"

enum class Event
{
	RingBell
};

/**
 * @brief EventSubject class serves as the Subject or the observable class
*/
class EventSubject
{
private:
	// ? observer are all Student and Professors
	std::vector<Observer *>	observers;

	void	ringBell() { // ? Notify function
		for (auto observer : observers)
			observer->update();
	}

	friend class Headmaster;

public:
	void	attach(Observer *observer) {
		if (!observer)
			return ;
		observers.push_back(observer);
	}

	void	dettach(Observer *observer) {
		auto	it = std::find(observers.begin(), observers.end(), observer);
		if (it != observers.end())
			observers.erase(it);
	}

};

#endif