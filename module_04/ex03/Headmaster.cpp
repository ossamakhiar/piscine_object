#include "Headmaster.hpp"

// ? HEADMASTER 
void	Headmaster::executeForms()
{
	std::vector<Form*>	_not_signed;
	for (auto form : _formToValidate)
	{
		if (form->is_signed()) {
			form->execute();
			continue ;
		}
		_not_signed.push_back(form);
	}

	std::cout << "Headmaster Mr. " << _name << ", Executes all the signed forms (";
	std::cout << _formToValidate.size() - _not_signed.size()  << " form)\n";
	_formToValidate = _not_signed;
}

void	Headmaster::executeForm(Form *form)
{
	Secretary	*sec = StaffList::get_secretary();

	if (!form->is_signed())
		throw std::runtime_error("Form note signed yet");
	std::cout << "Headmaster Mr. " << _name << ", executes a form\n";
	form->execute();

	// archive the form
	sec->archiveForm(form);
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

	if (!sec)
		throw std::runtime_error("We need to hire a secretary!");

	form = sec->createForm(request_type);
	if (!form)
		throw std::runtime_error("invalid request type");
	requester->fill(form);

	this->sign(form);
	this->executeForm(form);
	// ! Now in case of CourseFinished event i should emit to the student that he's graduate in this course
	// ! but where here or in the Form execution, for instant i'll putt it in the execution of the Form....
	return (true);
}
