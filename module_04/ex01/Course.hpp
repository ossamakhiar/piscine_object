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

public:
	Course(std::string p_name) : _name(p_name), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0) {

	}

	/**
	 * @brief set the number of class to graduate
	*/
	void	set_nums_gratuade(int p_nums) {
		_numberOfClassToGraduate = p_nums;
	}

	void	set__max_student(int p_max) {
		_maximumNumberOfStudent = p_max;
	}

	std::string	get_name() const {
		return (_name);
	}
	// ! method i added

	void assign(Professor* p_professor) {
		if (!p_professor)
			throw std::runtime_error("Bad Professor address");
		_responsable = p_professor;
	}

	// //this should be called by the a Staff professor when a Student made a Course subsribtion Form request, maybe not??
	void subscribe(Student* p_student) {
		if (!p_student)
			throw std::runtime_error("Bad Student address");
		_students.insert(p_student);
	}
};
