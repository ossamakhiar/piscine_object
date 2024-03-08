#include "Headmaster.hpp"

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

void	Headmaster::executeForm(Form *form)
{
	if (!form->is_signed())
		throw std::runtime_error("Form note signed yet");
	std::cout << "Headmaster Mr. " << _name << ", executes a form\n";
	form->execute();
	// ! i should remove it and tell the secretary to archive it
}


void	Headmaster::requireProfessorsAttendance()
{
	for (auto staff : StaffList::get_instance()->get_elements())
		if (Professor *prof = dynamic_cast<Professor*>(staff))
			prof->doClass();
}


bool	Headmaster::notify(Person *requester, FormType request_type)
{
	Form		*form;
	Secretary	*sec = StaffList::get_secretary();
	// bool		valide_request = false;

	if (!sec)
		throw std::runtime_error("We need to hire a secretary!");

	form = sec->createForm(request_type);
	requester->fill(form);

	this->sign(form);
	this->executeForm(form);

	// archive the form
	sec->archiveForm(form);
	// ! Now in case of CourseFinished event i should emit to the student that he's graduate in this course
	// ! but where here or in the Form execution, for instant i'll putt it in the execution of the Form....
	return (true);
}


// bool	Headmaster::notify(Student *student, FormType request_type)
// {
// 	Form	*form;
// 	Secretary	*sec = StaffList::get_secretary();

// 	if (!sec)
// 		throw std::runtime_error("We need to hire a secretary!");
// 	if (request_type == FormType::SubscriptionToCourse)
// 	{
// 		form = sec->createForm(FormType::SubscriptionToCourse); // this form of type NeedCourseCreationForm
// 		student->fill(form);
// 	}
// 	else
// 		return false;
// 	// if (!valide_request)
// 	// 	return (valide_request);
// 	this->sign(form);
// 	this->executeForm(form);
// 	return (true);
// }