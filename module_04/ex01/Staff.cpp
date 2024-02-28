#include "Staff.hpp"


Form*   Secretary::createForm(FormType p_formType)
{
	Form	*ret = NULL;
	if (p_formType == FormType::CourseFinished)
		ret = new CourseFinishedForm();
	else if (p_formType == FormType::NeedCourseCreation)
		ret = new NeedCourseCreationForm();
	else if (p_formType == FormType::NeedMoreClassRoom)
		ret = new NeedMoreClassRoomForm();
	else
		ret = new SubscriptionToCourseForm();
	return (ret );
}

void	Secretary::archiveForm()
{
	// Nothing for instant
}


void	Professor::assignCourse(Course* p_course)
{
	if (!p_course)
		return ;
	_currentCourse = p_course;
	std::cout << "Course " << p_course->get_name() << " assigned to Professor [name]\n";
}

void	Professor::doClass()
{
	// ? do class
}

void	Professor::closeCourse()
{
	// ? close Course
	_currentCourse = NULL;
}