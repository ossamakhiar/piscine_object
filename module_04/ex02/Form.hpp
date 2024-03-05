#pragma once

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};

// ** Command interface
class Form
{
protected: // ? think about that 
	FormType _formType;
	bool	_signed;
	bool	_executed;

public:
	Form(FormType p_formType) : _formType(p_formType), _signed(false), _executed(false) {

	}

	virtual ~Form() {
		
	}

	bool	is_signed() {
		return (_signed);
	}

	void sign() {
		_signed = true;
	}

	virtual void execute() = 0;
};
