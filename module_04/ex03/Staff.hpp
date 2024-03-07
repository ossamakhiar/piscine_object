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

// #include "ConcreteForm.hpp"