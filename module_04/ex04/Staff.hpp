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
		p_form->sign();
		std::cout << _name  << " has signed the form.\n";
	}
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
	void archiveForm(Form *form);
};

