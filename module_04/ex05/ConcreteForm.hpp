#pragma once

#include "Form.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "CourseList.hpp"
#include "RoomList.hpp"


/**
 * ? Concrete Commands (Forms)
*/


class CourseFinishedForm : public Form
{
private:
	// * course that would be set as finished
	Course	*completedCourse;
	Professor *professor;

public:
	CourseFinishedForm() : Form(FormType::CourseFinished), completedCourse(nullptr), professor(nullptr) {

	}
	~CourseFinishedForm() {}

	// ? Assigning  the course to be marked as completed
	void	set_course(Course *course) {
		if (!course)
			return ;
		completedCourse = course;
	}

	void	set_professor(Professor *p_professor)
	{
		professor = p_professor;
	}

	// TODO :: sign method which is checks for if the Form is filled

	void execute() {
		if (!completedCourse || !professor)
			throw std::runtime_error("Form should be filled first");
		// ? i should set the given course as finished and maybe also graduate all the Student who attend 
		// ? the numberOfClassToGraduate
		completedCourse->set_as_finished();
		professor->closeCourse();
		// mutate the state of the professor who is assigned to this course (by setting the currentCourse to empty) 

		// * Graduate some student
		// calling completedCourse->graduateStudents();
		for (auto student : completedCourse->get_subscribed_students())
			if ((*student)[completedCourse] >= completedCourse->get_nums_graduate())
				student->graduate(completedCourse);
	
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
	// std::string	course_name;
	// int			_numberOfClassToGraduate;
	// int			_maximumNumberOfStudent;

	ScheduledCourse	scheduledCourse;
	Professor		*professor;
	// ? same thing in this Form, storing the course will simplify the subsequent retrieval process
	Course		*course;

	// ! maybe holding all information about the Course like the number of class to graduate ...

public:
	NeedCourseCreationForm() : Form(FormType::NeedCourseCreation), professor(nullptr), course(nullptr) {}
	~NeedCourseCreationForm() {}

	void	set_scheduled_course(const ScheduledCourse& p_sch) {
		scheduledCourse = p_sch;
	}

	void	set_professor(Professor *p_professor) {
		professor = p_professor;
	}

	Course	*get_course() const {
		return (this->course);
	}

	void execute() {
		if (scheduledCourse.empty() || !professor)
			throw std::runtime_error("Form Should be filled");

		this->course	= new Course(scheduledCourse.get_name(), scheduledCourse.get_number_to_graduate(), scheduledCourse.get_max_students());
		CourseList::get_instance()->add_element(this->course);

		course->assign(professor);
		professor->assignCourse(course);

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
		if ((int)course->get_subscribed_students().size() >= course->get_max_student())
			throw std::runtime_error("Class has reached its capacity");
		course->subscribe(student);
	
		// std::cout << "Student " << student->get_name() << " subscribed to the course " << course->get_name() << "\n";
		_executed = true;
	}
};