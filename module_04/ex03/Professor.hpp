#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

#include "Headmaster.hpp";

class Professor : public Staff
{
private:
	Course* _currentCourse;

public:
	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();
};

#endif