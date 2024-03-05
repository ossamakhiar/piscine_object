#include "Course.hpp"


void    Course::subscribe(Student *p_student)
{
    if (_finished)
        throw std::runtime_error("Course finished");
    if (!p_student)
        throw std::runtime_error("Bad Student address");
    p_student->subscribe(this);
    _students.insert(p_student);
}