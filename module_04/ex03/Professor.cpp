#include "Professor.hpp"

// ? PROFESSOR
void	Professor::assignCourse(Course* p_course)
{
	if (!p_course)
		return ;
	_currentCourse = p_course;
	std::cout << "Course " << p_course->get_name() << " assigned to Professor [name]\n";
}

void	Professor::doClass()
{
	Headmaster  *headmaster = StaffList::getHeadmaster();

	if (!headmaster)
		throw std::runtime_error("School can't functions without a headmaster");

	if (!_currentCourse)
	{
		
	}
}

void	Professor::closeCourse()
{
	// ? close Course
	_currentCourse = NULL;
}