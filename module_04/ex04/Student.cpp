#include "Student.hpp"

bool	Student::isSubscribed(Course *p_course)
{
	for (auto course : _subscribedCourse)
		if (p_course == course.first)
			return (true);
	return (false);
}



void	Student::attendClass(Classroom* p_classroom)
{
	if (!p_classroom->get_course())
		throw std::runtime_error("No course assigned to this classroom.");
	if (!isSubscribed(p_classroom->get_course()))
		throw std::runtime_error("You must subscribe to the course "
								"before attending the class.");

	enterRoom(p_classroom);
	_subscribedCourse[p_classroom->get_course()]++;
	std::cout << "Student " << _name << " has attend a class " \
		<< p_classroom->get_course()->get_name() << "\n";
}



void	Student::graduate(Course* p_course)
{
	if (!isSubscribed(p_course))
		throw std::runtime_error("You're not subscribed to this Course");

	std::cout << _name << " has successfully graduated in " << p_course->get_name() << " course\n";
	_subscribedCourse.erase(p_course);
}



void	Student::subscribe(Course *course)
{
	Headmaster	*headmaster = StaffList::getHeadmaster();

	std::string	err_msg;
	err_msg = (!course) ? "Bad Course address" : \
			(!headmaster) ? "There's no Headmaster in the school" : \
			(_subscribedCourse.count(course)) ? "You're already subscribed to this course" : "";

	if (!err_msg.empty())
		throw std::runtime_error(err_msg);

	_desired_course = course;
	headmaster->notify(this, FormType::SubscriptionToCourse); // notify the Headmaster (Mediator) of that request
	_subscribedCourse[course] = 0;

	std::cout << "\e[1;34mStudent " << _name << " Subscribe to the Course " << course->get_name() << "\e[0m\n";
	// ? desired_course pointer has no role now; it is important just for form filling when the master asks for it.
	_desired_course = nullptr;
}



void	Student::fill(Form *form)
{
	SubscriptionToCourseForm	*s_form = dynamic_cast<SubscriptionToCourseForm *>(form);

	if (!s_form)
		return ;
	s_form->set_student(this);
	s_form->set_course(_desired_course);
}
