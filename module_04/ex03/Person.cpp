#include "Person.hpp"

void	Student::attendClass(Classroom* p_classroom)
{
		// ! i think i should check if that classroom is associated with one of the Courses that a Stundent sucribe to it
		// Change the Person::currentRoom
		if (!p_classroom->get_course())
			throw std::runtime_error("no Course Assigned to this classroom");

		bool	ok = false;
		for (auto course : _subscribedCourse)
			if (p_classroom->get_course() == course.first)
				ok = true;
		if (!ok)
			throw std::runtime_error("Student should subscribe to the course to attend the class");
		_currentRoom = p_classroom;
		_subscribedCourse[p_classroom->get_course()]++;
}

void	Student::graduate(Course* p_course)
{
	// ! check if the Student already subscribe to that Course first
	// ? i should first check if the Student has attend the Course::NumberOfClassToGraduate
	std::cout << _name << " has successfully graduated from " << "getcourse name\n"; // !!!!!
	_subscribedCourse.erase(p_course);
}