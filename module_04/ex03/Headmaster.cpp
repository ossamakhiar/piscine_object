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
