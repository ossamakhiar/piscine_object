#ifndef SINGLETONS_HPP
# define SINGLETONS_HPP

#include <iostream>
#include <mutex>
#include <set>
#include "Person.hpp"
#include "Staff.hpp"
#include <unistd.h>

// template<typename T>
// class Singleton
// {
// public:
//     static T*  get_instance()
//     {
//         std::lock_guard<std::mutex> guard(mtx);
//         if (!instance) // ? Lazy intialization
//             instance = new T();
		
//         return (instance);
//     }

//     // ! i should cleanup......
//     static void    cleanup() {
//         delete instance;
//         instance = NULL;
//     }

// protected:
//     static  T* instance;
//     static std::mutex  mtx; // it should be static so that static methods can access it

//     Singleton() {}
// };


/***
 * @brief Generic Singleton class template
 * @tparam T Type of elements to be stored in the singleton
*/
template<typename T>
class   Singleton
{
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


using StudentList = Singleton<Student*>;
using StaffList = Singleton<Staff*>;
using CourseList = Singleton<Course*>;
using RoomList = Singleton<Room*>;

// typedef SingletonDerived<Student *> StudentList;
// typedef SingletonDerived<Staff *> StaffList;
// typedef SingletonDerived<Course *> CourseList;
// typedef SingletonDerived<Room *> RoomList;

#endif
