#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

// #include "Person.hpp"
#include "Professor.hpp"

// ?Headmaster serves as the invoker for Form (Command) objects, signing and executing them.
// ?Additionally, Headmaster acts as a Mediator between the Secretary class and other classes
class Headmaster : public Staff
{
private:
  /**
   * The Invoker (Headmaster) does not depend on concrete command (Form) classes. The
   * ? Invoker passes a request to a receiver indirectly, by executing a command.
   */
	std::vector<Form*> _formToValidate;
	
public:
	Headmaster(std::string name) : Staff(name) {
		
	}

	void receiveForm(Form* p_form) {
		if (!p_form)
			return ;
		_formToValidate.push_back(p_form);
	}

	// Validates all received forms by signing them.
    // This function is typically called before form execution.
	void	signForms() {
		for (auto form : _formToValidate)
			form->sign();
		std::cout << "Mr. " << _name << " Headmaster signs all the given forms\n";
	}

	// ? this function will be call after signing 0..* Form to be executed and take place in the system?
	void	executeForms();
	void	executeForm(Form *form);

	void	requireProfessorsAttendance();


	bool	notify(Person *requester, FormType	request_type);
};

#include "StaffList.hpp"

#endif
