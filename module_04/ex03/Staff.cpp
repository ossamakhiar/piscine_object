#include "Staff.hpp"
#include "ConcreteForm.hpp"


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

