#pragma once

#include "Singletons.hpp"
#include "Form.hpp"


/**
 * ? Concrete Commands (Forms)
*/


class CourseFinishedForm : public Form
{
private:
	// * course that would set as finished
	Course	*completedCourse;

public:
	CourseFinishedForm() : Form(FormType::CourseFinished), completedCourse(nullptr) {

	}
	~CourseFinishedForm() {}

	// ? Assigning  the course to be marked as completed
	void	set_course(Course *course) {
		if (!course)
			return ;
		completedCourse = course;
	}

	// TODO :: sign method which is checks for if the Form is filled

	void execute() {
		if (!completedCourse)
			throw std::runtime_error("Form should be filled first");
		// ? i should set the given course as finished and maybe also graduate all the Student who attend 
		// ? the numberOfClassToGraduate
		completedCourse->set_as_finished();
		// completedCourse->graduate_student();
	
		std::cout << "Course " << completedCourse->get_name() << " is Completed\n";
		_executed = true;
	}
};

class NeedMoreClassRoomForm : public Form
{
private:
	// ? i think it would be beneficial to save the created classroom, enabling easy retrieval at a later time
	// ? Classroom that Will be created
	Classroom *classroom;

public:
	NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom), classroom(nullptr) {

	}
	~NeedMoreClassRoomForm() {}

	Classroom	*get_classroom() const {
		return (classroom);
	}

	// * execution of this form implies creation of a Classroom and store it in the RoomList
	void execute() {
		classroom = new Classroom();
		RoomList::get_instance()->add_element(classroom);

		std::cout << "Classroom has been created id " << classroom->get_id() << "\n";
		_executed = true;
	}
};

class NeedCourseCreationForm : public Form
{
private:
	// ? same thing in this Form, storing the course will simplify the subsequent retrieval process
	std::string	course_name;
	Course	*course;

	// ! maybe holding all information about the Course like the number of class to graduate ...

public:
	NeedCourseCreationForm() : Form(FormType::NeedCourseCreation), course_name(""), course(nullptr) {}
	~NeedCourseCreationForm() {}

	void	set_course_name(const std::string& p_name) {
		course_name = p_name;
	}

	Course	*get_course() const {
		return (this->course);
	}

	void execute() {
		// ? the question is where would name be got
		this->course	= new Course(course_name);
		// ? should i add it to the Course List ?????????
		CourseList::get_instance()->add_element(this->course);

		std::cout << "Course has been created with name " << this->course->get_name() << "\n";
		_executed = true;
	}
};

class SubscriptionToCourseForm : public Form
{
private:
	Student	*student;
	Course	*course;

public:
	SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse), student(nullptr), course(nullptr) {}
	~SubscriptionToCourseForm() {}

	// ? Assigning the Student who initiated that Form 
	void	set_student(Student *p_student)
	{
		this->student = p_student;
	}

	// ? Assigning the Course that Student wants to enroll in
	void	set_course(Course *p_course)
	{
		this->course = p_course;
	}

	Student	*get_student() const {
		return (student);
	}

	Course	*get_course() const {
		return (course);
	}


	// ? execution of this form means subscribe the Student to the course
	void execute() {
		if (!student || !course)
			throw std::runtime_error("Form should be filled first");
			// return ; // ! i should throw some kind of errors
		course->subscribe(student);
	
		std::cout << "Student " << student->get_name() << " subscribed to the course " << course->get_name() << "\n";
		_executed = true;
	}
};