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


class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	void receiveForm(Form* p_form) {
		if (!p_form)
			return ;
		_formToValidate.push_back(p_form);
	}
};

class Secretary : public Staff
{
private:

public:
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