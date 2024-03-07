#ifndef PERSON_HPP
# define PERSON_HPP


#include <iostream>
#include <string>
#include <map>
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

	virtual ~Person() {

	}

	virtual void	fill(Form *form) { // i will reduce the direct dependency between the Headmaster and who request the Form
		std::cout << "Nothing for a regular person\n";
		(void)form;
	}

	Room* room() {
		return (_currentRoom);
	}

	// * TEST
	void	introduce() {
		std::cout << "Person name is " << _name << ", in room " << _currentRoom << "\n"; 
	}
};


#endif