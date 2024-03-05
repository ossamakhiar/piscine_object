#include "Staff.hpp"

// ? SECRETARY
Form*   Secretary::createForm(FormType p_formType)
{
	Form	*ret = nullptr;
	if (p_formType == FormType::CourseFinished)
		ret = new CourseFinishedForm();
	if (p_formType == FormType::NeedCourseCreation)
		ret = new NeedCourseCreationForm();
	if (p_formType == FormType::NeedMoreClassRoom)
		ret = new NeedMoreClassRoomForm();
	if (p_formType == FormType::SubscriptionToCourse)
		ret = new SubscriptionToCourseForm();

	// ! I should amend about that
	if (!ret)
		throw std::runtime_error("No form of this Type");
	return (ret);
}


void	Secretary::archiveForm()
{
	// Nothing for instant
}



// ? HEADMASTER 
void	Headmaster::executeForms()
{
	std::vector<Form*>	_not_signed;
	for (auto form : _formToValidate)
	{
		// ? checking if the Form signed first then execute it
		if (form->is_signed())
			form->execute();
		else
			_not_signed.push_back(form);
	}

	// ? remove all the signed forms
	std::cout << "Headmaster Mr. " << _name << ", Executes all the signed forms (";
	std::cout << _formToValidate.size() - _not_signed.size()  << " form)\n";
	_formToValidate = _not_signed;
}




// ? PROFESSOR
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