#pragma once

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};

class Form
{
protected: // ? think about that 
	FormType _formType;

public:
	Form(FormType p_formType) : _formType(p_formType)
	{

	}

	virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
private:

public:
	CourseFinishedForm() : Form(FormType::CourseFinished) {

	}
	~CourseFinishedForm() {}

	void execute() {

	}
};

class NeedMoreClassRoomForm : public Form
{
private:

public:
	NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {

	}
	~NeedMoreClassRoomForm() {}

	void execute() {

	}
};

class NeedCourseCreationForm : public Form
{
private:

public:
	NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {}
	~NeedCourseCreationForm() {}

	void execute() {

	}
};

class SubscriptionToCourseForm : public Form
{
private:

public:
	SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {}
	~SubscriptionToCourseForm() {}

	void execute() {

	}
};