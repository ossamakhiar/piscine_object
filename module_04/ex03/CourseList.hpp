#ifndef COURSE_LIST_HPP
# define COURSE_LIST_HPP

#include "Course.hpp"
#include "Singletons.hpp"

class	CourseList : public Singleton<Course*>
{
private:
	CourseList();
public:
	// Nothing special
};

#endif