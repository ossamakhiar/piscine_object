#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

#include "Student.hpp"
#include "Professor.hpp"

// ? Headmaster plays as an invoker to the Form (Command) by sign it and execute it 
// ???? Headmaster also plays as Mediator between the Secratery class and other classes
class Headmaster : public Staff
{
private:
  /**
   * The Invoker (Headmaster) does not depend on concrete command (Form) classes. The
   * ? Invoker passes a request to a receiver indirectly, by executing a command. ???????????????
   */
	std::vector<Form*> _formToValidate;
	// std::map<Request, void (Headmaster::*)(void)>	requests;
	
public:
	Headmaster(std::string name) : Staff(name) {
		
	}

	void receiveForm(Form* p_form) {
		if (!p_form)
			return ;
		_formToValidate.push_back(p_form);
	}

	// ? it coherent to have this function which called before the form execution
	void	signForms() {
		for (auto form : _formToValidate)
			form->sign();
		std::cout << "Mr. " << _name << " Headmaster signs all the given forms\n";
	}

	// ? this function will be call after signing 0..* Form to be executed and take place in the system?
	void	executeForms();
	void	executeForm(Form *form);

	void	requireProfessorsAttendance();


	bool	notify(Professor *professor, FormType	request_type);
	bool	notify(Student *student, FormType	request_type);
};

#include "StaffList.hpp"

#endif
