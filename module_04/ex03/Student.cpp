#include "Student.hpp"

void	Student::attendClass(Classroom* p_classroom)
{
	bool	ok = false;

	if (!p_classroom->get_course())
		throw std::runtime_error("no Course Assigned to this classroom");
	for (auto course : _subscribedCourse)
		if (p_classroom->get_course() == course.first)
			ok = true;
	if (!ok)
		throw std::runtime_error("Student should subscribe to the course to attend the class");
	enterRoom(p_classroom);
	_subscribedCourse[p_classroom->get_course()]++;

	std::cout << "Student " << _name << " has attend a class " << p_classroom->get_course()->get_name() << "\n";
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

	std::string	err_msg = (!course) ? "Bad Course address" : (!headmaster) ? "There's no Headmaster in the school" : \
							(_subscribedCourse.count(course)) ? "You're already subscribed to this course" :"";

	if (!err_msg.empty())
		throw std::runtime_error(err_msg);
	_want_to_register = course;

	headmaster->notify(this, FormType::SubscriptionToCourse);	// this may throw an error when executing the form since the class has a capacity

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