#ifndef COURSE_LIST_HPP
# define COURSE_LIST_HPP

#include "../Course.hpp"
#include "../Singletons.hpp"

class	CourseList : public Singleton<Course*>
{
private:
	CourseList();
public:
	// Nothing special

	static Course* get_course(const std::string& name) {
		for (auto course : get_instance()->get_elements())
			if (course->get_name() == name)
				return (course);
		return (nullptr);
	}
};

#endif