#include "Student.hpp"

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

	std::cout << _name << " has successfully graduated in " << p_course->get_name() << " course\n"; // !!!!!
	_subscribedCourse.erase(p_course);
}

void	Student::subscribe(Course *course)
{
	Headmaster	*headmaster = StaffList::getHeadmaster();

	if (!headmaster)
		throw std::runtime_error("There's no Headmaster in the school");
	if (!course)
		throw std::runtime_error("Bad Course address");
	if (_subscribedCourse.count(course))
		throw std::runtime_error("You're already subscribed to this course");
	_want_to_register = course;

	headmaster->notify(this, FormType::SubscriptionToCourse);
	_subscribedCourse[course] = 0; // just subscribed so no attendance
	std::cout << "\e[1;34mStudent " << _name << " Subscribe to the Course " << course->get_name() << "\e[0m\n";

	// ? want to register has no role now it important just for form filling when the master ask for this
	_want_to_register = nullptr;
}


void	Student::fill(Form *form)
{
	SubscriptionToCourseForm	*s_form = dynamic_cast<SubscriptionToCourseForm *>(form);

	if (!s_form)
		return ;
	s_form->set_student(this);
	s_form->set_course(_want_to_register);
}