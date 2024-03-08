#ifndef	ROOM_HPP
# define ROOM_HPP

#include <vector>
#include <set>
#include <iostream>
// #include "Course.hpp"
#include "Form.hpp"

class Person;
class Course;

class Room
{
private:
	static long long	_id_counter; // I added this static to make a unique id at any creation of a Room object

	long long ID;
	std::set<Person*> _occupants;
	// std::vector<Person*> _occupants;

public:
	Room() {
		this->ID = _id_counter;
		_id_counter++;
	}

	virtual ~Room() {

	}

	// ? Getter
	long long get_id() {
		return (this->ID);
	}


	bool canEnter(Person*) {
		return (true);
	}
	void enter(Person* p_person) {
		if (!p_person)
			return ; // Should inform the user for good error debuging
		_occupants.insert(p_person);
	}

	void exit(Person* p_person) {
		_occupants.erase(p_person);
	}
	
	void printOccupant();
};

class Classroom : public Room
{
private:
	Course* course;

public:
	Classroom() : course(nullptr) {
		// std::cout << "Constr\n";
		// std::cout << course << "\n";
	}

	void assignCourse(Course* p_course) {
		if (!p_course)
			return ; // ! Back Here..
		course = p_course;
	}

	void	unassignCourse() {
		course = nullptr;
	}

	bool	free() const {
		return (!course);
	}

	// ! getter, no need maybe
	Course	*get_course() const {
		return (course); // course currently running in that classroom
	}
};


class SecretarialOffice: public Room
{
private:
	std::set<Form*> _archivedForms;

public:

	void	archiveForm(Form *form) {
		_archivedForms.insert(form);
	}
};


class HeadmasterOffice : public Room
{
private:

public:

};


class StaffRestRoom : public Room
{
private:

public:

};


class Courtyard : public Room
{
private:

public:

};

#include "Person.hpp"
#include "Course.hpp"

#endif