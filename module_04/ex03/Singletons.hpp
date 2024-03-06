#ifndef SINGLETONS_HPP
# define SINGLETONS_HPP

#include <iostream>
#include <mutex>
#include <set>
#include "Person.hpp"
#include "Staff.hpp"
#include <unistd.h>

/***
 * @brief Generic Singleton class template
 * @tparam T Type of elements to be stored in the singleton
*/
template<typename T>
class   Singleton
{
// protected:
private:
	std::set<T> elements;


	static  Singleton<T>* instance; // Holding one single instance of the Singleton class
	static std::mutex  mtx; // it should be static so that static methods can access it

	// Private constructor to enforce singleton pattern
	Singleton() {}

public:
	static Singleton<T>*  get_instance()
	{
		std::lock_guard<std::mutex> guard(mtx);
		if (!instance) // ? Lazy initialization: create instance if it doesn't exist
			instance = new Singleton<T>();
		
		return (instance);
	}

	void    add_element(T p_element)
	{
		// mtx.lock();
		std::lock_guard<std::mutex> guard(mtx);
		elements.insert(p_element);
		// mtx.unlock();
	}


	// TODO: Define get_element and remove_element methods
	T	get_element(bool (*check_existence)(T)) {
		for (auto element : elements)
			if (check_existence(element))
				return (element);
		// what if the T is not a pointer
		return (nullptr);
	}

	std::set<T>&    get_elements()
	{
		return (elements);
	}

	~Singleton() {
		std::cout << "\e[1;33mDestruction of Singleton\e[0m\n";
	}
};

template<typename T>
Singleton<T>* Singleton<T>::instance = nullptr;

template<typename T>
std::mutex Singleton<T>::mtx;

class	StaffList : public Singleton<Staff *>
{
private:
	StaffList();

public:
	static	Headmaster* getHeadmaster() {
		for (auto staff : get_instance()->get_elements())
			if (dynamic_cast<Headmaster*>(staff))
				return dynamic_cast<Headmaster*>(staff);
		return (nullptr);
	}
};

class	StudentList : public Singleton<Student*>
{
private:
	StudentList();
public:
	// Nothing special
};

class	CourseList : public Singleton<Course*>
{
private:
	CourseList();
public:
	// Nothing special
};

class	RoomList : public Singleton<Room*>
{
private:
	RoomList();
public:
	// Nothing special
};

#endif
