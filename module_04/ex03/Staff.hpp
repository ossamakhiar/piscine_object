#pragma once

#include "Person.hpp"
#include "Form.hpp"

class Staff : public Person
{
private:

public:
	Staff(std::string name) : Person(name) {

	}

	// ? getter
	std::string	get_name() const {
		return (_name);
	}

	void sign(Form* p_form) {
		std::cout << "Form has signed the form.\n";
		(void)p_form;
	}
};

// ? Headmaster plays as an invoker to the Form (Command) by sign it and execute it 
class Headmaster : public Staff
{
private:
  /**
   * The Invoker (Headmaster) does not depend on concrete command or receiver (Form) classes. The
   * ? Invoker passes a request to a receiver indirectly, by executing a command. ???????????????
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

	// ? it coherent to have this function which called before the form execution
	void	signForms() {
		for (auto form : _formToValidate)
			form->sign();
		std::cout << "Mr. " << _name << " Headmaster signs all the given forms\n";
	}

	// ? this function will be call after signing 0..* Form to be execute and take place in the system?
	void	executeForms();
};

class Secretary : public Staff
{
private:

public:
	Secretary(std::string name) : Staff(name) {

	}

	~Secretary() {

	}

	// ? Secretary in this case functions as a Factory object...
	Form* createForm(FormType p_formType);

	void archiveForm();
};

class Professor : public Staff
{
private:
	Course* _currentCourse;

public:
	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();
};

#include "ConcreteForm.hpp"