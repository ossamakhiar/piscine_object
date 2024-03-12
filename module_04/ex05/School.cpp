#include "School.hpp"

School::School(const std::string& p_school_name, const std::string& headmaster_name) : school_name(p_school_name)
{
	headmaster = new Headmaster(headmaster_name);
	secretary = new Secretary("alica steven");
	StaffList::get_instance()->add_element(headmaster);
	StaffList::get_instance()->add_element(secretary);

	bell = new EventSubject();
}

School::~School()
{
 // !! Back here to cleanup
	delete headmaster;
	delete secretary;
	delete bell;
}

void	School::runDayRoutine()
{
	for (int i = 0; i < 4; i++)
	{
		launchClasses();
		if (i == 1)
		{
			// ? lunch time
			requestRingBell(Event::LunchTime);
			continue ;
		}
		requestRingBell(Event::RingBell);
	}
}

void	School::launchClasses()
{
	headmaster->requireProfessorsAttendance();
}

void	School::requestRingBell(Event event)
{
	headmaster->ringBell(event);
}

void	School::recruteProfessor()
{
	Professor	*professor = new Professor("prof name");
	bell->attach(professor);
	StaffList::get_instance()->add_element(professor);
}

void	School::recruteStudent()
{
	Student	*student = new Student("student name");
	bell->attach(student);
	StudentList::get_instance()->add_element(student);
}

Course*	School::getCourse(std::string p_name)
{
	return (CourseList::get_course(p_name));
}

Secretary*	School::getSecretary()
{
	return (secretary);
}

Headmaster*	School::getHeadmaster()
{
	return (headmaster);
}

std::vector<Student*>	School::getStudents()
{
	std::set<Student *>	students = StudentList::get_instance()->get_elements();
	return (std::vector<Student *>(students.begin(), students.end()));
}

std::vector<Professor*>	School::getProfessors()
{
	std::vector<Professor *>	profs;

	for (auto staff : StaffList::get_instance()->get_elements())
		if (Professor *ret = dynamic_cast<Professor *>(staff))
			profs.push_back(ret);
	return (profs);
}

// void    graduationCeremony();