#include "Person.hpp"

void	Student::attendClass(Classroom* p_classroom)
{
		// ! i think i should check if that classroom is associated with one of the Courses that a Stundent sucribe to it
		// Change the Person::currentRoom
		bool	ok = false;
		for (std::set<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it)
			if (p_classroom->get_course() == (*it))
				ok = true;
		if (!ok)
			throw std::runtime_error("Student should subscribe to the course to attend the class");
		_currentRoom = p_classroom;
}

void	Student::graduate(Course* p_course)
{
	// ! check if the Student already subscribe to that Course first
	// ? i should first check if the Student has attend the Course::NumberOfClassToGraduate
	std::cout << _name << " has successfully graduated from " << "getcourse name\n"; // !!!!!
	_subscribedCourse.erase(p_course);
}