#include "Headmaster.hpp"
#include "Professor.hpp"
#include "StudentList.hpp"
#include "CourseList.hpp"
#include <unistd.h>

int main(void)
{
    Headmaster      *headmaster = new Headmaster("Ethan Johnson");
    ScheduledCourse s("Introduction to Dynamic programming", 5, 20);
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
    headmaster->notify(prof_alan, FormType::NeedCourseCreation);

    s_oussama->subscribe(CourseList::get_course("Introduction to Dynamic programming"));
    s_john->subscribe(CourseList::get_course("Introduction to Dynamic programming"));

    EventSubject*   bell = new EventSubject();
    bell->attach(prof_alan);
    bell->attach(s_oussama);
    bell->attach(s_john);
    headmaster->setBell(bell);

    std::cout << "\e[1;32mstarting Courses\e[0m\n";
    headmaster->requireProfessorsAttendance();

    for (int i = 0; i < 5; i++)
    {
        std::cout << "pause\n";
        sleep(5);
        headmaster->ringBell();
    }

    std::cout << "End of the day\n";
    return 0;
}
