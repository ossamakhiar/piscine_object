#ifndef STUDENT_LIST_HPP
# define STUDENT_LIST_HPP

#include "../Student.hpp"
#include "../Singletons.hpp"

class	StudentList : public Singleton<Student*>
{
private:
	StudentList();
public:
	// Nothing special
};

#endif