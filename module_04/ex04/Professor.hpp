#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

#include "observer.hpp"
#include "Course.hpp"
#include "Staff.hpp"
#include <assert.h>

class	ScheduledCourse
{
private:
	std::string	name;
	int			number_of_class_graduate;
	int			max_students;

	// ! No need for deep copy but this comment to remind me in case...

public:
	ScheduledCourse() : name(""), number_of_class_graduate(0), max_students(0) {

	}

	/**
	 * @param p_name name of the course
	 * @param n_grad the number of classes to graduate
	 * @param cp the max number of student
	*/
	ScheduledCourse(const std::string& p_name, int n_grad, int cp) : name(p_name), number_of_class_graduate(n_grad), max_students(cp) {

	}

	bool	empty() {
		return (name.empty());
	}

	std::string	get_name() const {
		return (name);
	}

	int	get_max_students() const {
		return (max_students);
	}

	int	get_number_to_graduate() const {
		return (number_of_class_graduate);
	}

};

class Professor : public Staff, public Observer
{
private:
	Course* 		_currentCourse;
	Classroom*		_classroom;

	ScheduledCourse scheduled_course; // a vector or *queue* is more appropriate
	int				_currentCourseAttendance;

public:
	Professor(std::string name) : Staff(name), _currentCourse(nullptr), _classroom(nullptr), _currentCourseAttendance(0) {
		
	}

	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();

	void	schedule_course(const ScheduledCourse& s);
	void	fill(Form *form) override;

	void	update() override; // implement update method, declared by the Observer interface 
};

#include "Headmaster.hpp"
#include "ConcreteForm.hpp"


#endif