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
	// std::vector<Course*> _subscribedCourse;

	std::map<Course*, int> _subscribedCourse; // ? mapping every course with the number of attendance

	// // ? it make sense to have this variable to attendance but wait it should be for every Course
	// int	attendanceCount;

public:
	Student(std::string name) : Person(name) {}
	~Student() {}

	// ? Getter
	std::string	get_name() const {
		return (_name);
	}

	int	get_attendance_nums(Course *course) const {
		if (_subscribedCourse.count(course) == 0)
			return (0);
		return (_subscribedCourse.at(course));
	}

	// this function is called by the Course that the Student requested to subscribe
	void	subscribe(Course *course) {
		if (!course)
			throw std::runtime_error("Bad Course address");
		if (_subscribedCourse.count(course))
			throw std::runtime_error("You're already subscribed to this course");
		_subscribedCourse[course] = 0;
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