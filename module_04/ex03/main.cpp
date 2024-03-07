#include "Headmaster.hpp"
#include "Professor.hpp"
#include "StudentList.hpp"

int main(void)
{
    Headmaster  *headmaster = new Headmaster("Ethan Johnson");
    ScheduledCourse s("Intoduction to Dynamic programming", 10, 20);
    Professor   *prof_alan = new Professor("Alan walker");
    Student     *s_oussama = new Student("Oussama khiar"); 
    Student     *s_john = new Student("john doe");

    StaffList::get_instance()->add_element(headmaster);
    StaffList::get_instance()->add_element(prof_alan);

    StudentList::get_instance()->add_element(s_oussama);
    StudentList::get_instance()->add_element(s_john);

    prof_alan->schedule_course(s);

    std::cout << "\e[1;32m**************\e[0m\n";

    headmaster->requireProfessorsAttendance();


    return 0;
}