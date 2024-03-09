#ifndef STUDENT_HPP
# define STUDENT_HPP

#include "Person.hpp"

class Student : public Person
{
private:
	Course	*_desired_course; // Holds the course the student wishes to register, used when the Headmaster asks the student to fill a form for the desired course

	std::map<Course*, int> _subscribedCourse; // ? Maps each subscribed course to the number of attendances

	bool	isSubscribed(Course *p_course);

public:
	Student(std::string name) : Person(name), _desired_course(nullptr) {}
	~Student() {}

	void	attendClass(Classroom* p_classroom);
	void	graduate(Course* p_course);
	void	subscribe(Course *course);
	void	fill(Form *form) override;

	void exitClass() {
		if (!_currentRoom)
			return ;
		_currentRoom->exit(this);
		_currentRoom = NULL;
	}

	int	operator[](Course *course) const {
		if (_subscribedCourse.count(course) == 0)
			return (0);
		return (_subscribedCourse.at(course));
	}
};

#include "ConcreteForm.hpp"
#include "Headmaster.hpp"

#endif
