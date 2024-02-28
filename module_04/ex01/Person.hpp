#ifndef PERSON_HPP
# define PERSON_HPP


#include <iostream>
#include <string>
#include <set>
#include "Room.hpp"
#include "Course.hpp"

class Person
{
protected: // i should back to this
	std::string _name;
	Room* _currentRoom;

public:
	Person(std::string p_name) : _name(p_name), _currentRoom(NULL) {

	};

	virtual ~Person() {}

	// ! I Should add a room setter....

	Room* room() {return (_currentRoom);}


	// * TEST
	void	introduce() {
		std::cout << "Person name is " << _name << ", in room " << _currentRoom << "\n"; 
	}
};

class Student : public Person
{
private:
	std::set<Course*> _subscribedCourse;
	// std::vector<Course*> _subscribedCourse;

public:
	Student(std::string name) : Person(name) {}
	~Student() {}

	// ? Getter
	std::string	get_name() const {
		return (_name);
	}

	void attendClass(Classroom* p_classroom);
	void graduate(Course* p_course);

	void exitClass() {
		// exiting normaly but which class, i think the Room that is listed in the Person class
		// mutate Person::currentRoom
		_currentRoom = NULL;
	}
};


#endif