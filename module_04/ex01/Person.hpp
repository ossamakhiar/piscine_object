#pragma once

#include <string>
#include <set>
#include "Room.hpp"
#include "Course.hpp"

class Person
{
private:
	std::string _name;
	Room* _currentRoom;

public:
	Person(std::string p_name) : _name(p_name) {

	};

	// ! I Should add a room setter....

	Room* room() {return (_currentRoom);}
};

class Student : public Person
{
private:
	std::set<Course*> _subscribedCourse;
	// std::vector<Course*> _subscribedCourse;

public:
	void attendClass(Classroom* p_classroom) {
		// ....
	}

	void exitClass() {
		// ....
	}

	void graduate(Course* p_course) {
		// ...
	}
};
