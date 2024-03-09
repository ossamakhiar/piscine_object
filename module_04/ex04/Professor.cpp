#include "Professor.hpp"


// ? PROFESSOR
void	Professor::assignCourse(Course* p_course)
{
	if (!p_course)
		return ;
	_currentCourse = p_course;
	std::cout << "Course " << p_course->get_name() << " assigned to Professor " << _name << "\n";
}

void	Professor::doClass()
{
	Headmaster  *headmaster = StaffList::getHeadmaster();

	if (!headmaster)
		throw std::runtime_error("School can't functions without a headmaster");

	if (!_currentCourse)
	{
		headmaster->notify(this, FormType::NeedCourseCreation);
		assert(_currentCourse);
		std::cout << "Professor " << _name << " now assigned to course \"" << _currentCourse->get_name() << "\"\n";
		return ;
	}

	if (_currentCourseAttendance >= _currentCourse->get_nums_graduate())
	{
		std::cout << _name << " let graduate some Students\n";
		headmaster->notify(this, FormType::CourseFinished);
		return ;
	}

	Classroom *classroom = RoomList::get_free_classroom();
	if (!classroom)
	{
		headmaster->notify(this, FormType::NeedMoreClassRoom);
		classroom = RoomList::get_free_classroom();
		enterRoom(classroom);
	}

	classroom->assignCourse(_currentCourse);
	std::cout << "Following doing the current course \"" << _currentCourse->get_name() << "\" Session " << _currentCourseAttendance << "\n";
	_currentCourseAttendance++;
	for (auto student : _currentCourse->get_subscribed_students())
		student->attendClass(classroom);

	// !!! TEST
	classroom->printOccupant();

	// ? exiting the Class Emmmmmmmmmmmm????
	for (auto student : _currentCourse->get_subscribed_students())
		student->exitClass();
	classroom->unassignCourse();

	exitRoom();

	classroom->printOccupant();
}

void	Professor::closeCourse()
{
	// ? close Course
	if (!_currentCourse)
		return ;
	std::cout << "Current Course \"" << _currentCourse->get_name() << "\" has been finished! Close the course\n";
	_currentCourse = NULL;
	_currentCourseAttendance = 0;
}


void	Professor::schedule_course(const ScheduledCourse& s)
{
	this->scheduled_course = s;
}

void	Professor::fill(Form *form)
{
	std::cout << "filling the form profff " << _name << "\n";
	if (NeedCourseCreationForm *ret = dynamic_cast<NeedCourseCreationForm *>(form))
	{
		ret->set_scheduled_course(scheduled_course);
		ret->set_professor(this);
		return ;
	}

	if (CourseFinishedForm *ret = dynamic_cast<CourseFinishedForm *>(form))
	{
		ret->set_course(_currentCourse);
		ret->set_professor(this);
	}
}