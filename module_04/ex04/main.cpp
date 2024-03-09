#include "Headmaster.hpp"
#include "Professor.hpp"
#include "StudentList.hpp"
#include "CourseList.hpp"

int main(void)
{
    Headmaster      *headmaster = new Headmaster("Ethan Johnson");
    ScheduledCourse s("Introduction to Dynamic programming", 1, 20);
    Professor       *prof_alan = new Professor("Alan walker");
    Secretary       *sofia = new Secretary("sofia alavertz");
    Student         *s_oussama = new Student("Oussama khiar"); 
    Student         *s_john = new Student("john doe");

    Room    *sec_office = new SecretarialOffice();

    StaffList::get_instance()->add_element(headmaster);
    StaffList::get_instance()->add_element(prof_alan);
    StaffList::get_instance()->add_element(sofia);

    StudentList::get_instance()->add_element(s_oussama);
    StudentList::get_instance()->add_element(s_john);

    RoomList::get_instance()->add_element(sec_office);

    prof_alan->schedule_course(s);

    std::cout << "\e[1;32m**************\e[0m\n";

    headmaster->requireProfessorsAttendance();

    std::cout << "Course just created ********\n";

    Course  *dp = CourseList::get_course("Introduction to Dynamic programming");
    s_oussama->subscribe(dp);

    headmaster->requireProfessorsAttendance();

    std::cout << "\e[1;35mIT SHOULD GRADUATE THE STUDETN NOW\n\e[0m";

    headmaster->requireProfessorsAttendance();

    std::cout << prof_alan->room() << "\n";

    return 0;
}
