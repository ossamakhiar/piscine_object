#pragma once

#include <string>
#include <set>
#include <stdexcept>

class Professor;
class Student;

class Course
{
private:
	std::string _name;
	Professor* _responsable;
	std::set<Student*> _students;// change from std:;vector to std::set it better
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;

	bool	_finished;

	// ? I shoud add a state variable that indicate if the course is still running or has been finished
	// ? and maybe Storing all graduated Student also, maybe???

public:
	Course() : _numberOfClassToGraduate(0), _maximumNumberOfStudent(0), _finished(false) {

	}
	Course(std::string p_name) : _name(p_name), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0) {

	}

	void	set_name(const std::string& name) {
		_name = name;
	}

	/**
	 * @brief set the number of class to graduate
	*/
	void	set_nums_graduate(int p_nums) {
		_numberOfClassToGraduate = p_nums;
	}

	void	set__max_student(int p_max) {
		_maximumNumberOfStudent = p_max;
	}

	void	set_as_finished() {
		this->_finished = true;
	}

	std::string	get_name() const {
		return (_name);
	}

	int	get_max_student() const {
		return (_maximumNumberOfStudent);
	}

	int	get_nums_graduate() const {
		return (_numberOfClassToGraduate);
	}

	bool	is_finished() const {
		return (_finished);
	}
	// ! method i added ^

	void assign(Professor* p_professor) {
		if (!p_professor)
			throw std::runtime_error("Bad Professor address");
		_responsable = p_professor;
	}

	// this should be called by the a Staff professor when a Student made a Course subsribtion Form request, maybe not??
	void subscribe(Student* p_student);
};

#include "Person.hpp"
