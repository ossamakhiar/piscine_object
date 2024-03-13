#ifndef SCHOOL_HPP
# define SCHOOL_HPP


#include "Headmaster.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "StudentList.hpp"
#include "CourseList.hpp"
#include "EventSubject.hpp"

/**
 * @brief School class server as facade or interface to access the education subsystem
*/
class	School
{
private:
	std::string	school_name;

	Headmaster		*headmaster;
	Secretary		*secretary;
	EventSubject	*bell;

public:
	School(const std::string&, const std::string&);
	~School();

	void	runDayRoutine();
	void	launchClasses();
	void	requestRingBell(Event event);
	void	recruteProfessor(const std::string& prof_name);
	void	recruteStudent(const std::string& student_name);

	Course*					getCourse(std::string p_name);
	Secretary*				getSecretary();
	Headmaster*				getHeadmaster();
	std::vector<Student*>	getStudents();
	std::vector<Professor*>	getProfessors() ;

	void    graduationCeremony();
};

#endif