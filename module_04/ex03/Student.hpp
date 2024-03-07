#ifndef STUDENT_HPP
# define STUDENT_HPP

#include "Person.hpp"

class Student : public Person
{
private:
	// std::vector<Course*> _subscribedCourse;
	Course	*_want_to_register;

	std::map<Course*, int> _subscribedCourse; // ? mapping every course with the number of attendance

public:
	Student(std::string name) : Person(name), _want_to_register(nullptr) {}
	~Student() {}

	// ? Getter
	std::string	get_name() const {
		return (_name);
	}


	void attendClass(Classroom* p_classroom);
	void graduate(Course* p_course);

	void	subscribe(Course *course);
	void	fill(Form *form);

	void exitClass() {
		// exiting normaly but which class, i think the Room that is listed in the Person class
		// mutate Person::currentRoom
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