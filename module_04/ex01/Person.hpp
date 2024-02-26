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
		// ! i think i should check if that classroom is associated with one of the Courses that a Stundent sucribe to it
		// Change the Person::currentRoom
		// ....
	}

	void exitClass() {
		// exiting normaly but which class, i think the Room that is listed in the Person class
		// mutate Person::currentRoom
		// ....
	}

	void graduate(Course* p_course) {
		// ???
		// ...
	}
};
