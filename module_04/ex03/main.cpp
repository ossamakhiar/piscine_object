#include "Person.hpp"
#include "Staff.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Form.hpp"
#include "Singletons.hpp"
#include "ConcreteForm.hpp"
#include <thread>

// void addStudents() {
//     for (int i = 0; i < 5; ++i) {
//         StudentList::get_instance()->add_element(new Student("oussama"));
//     }
// }

bool    check_student_existence(Student *s)
{
    if (s->get_name() == "khiar")
        return (true);
    return (false);
}

bool    get_first_room(Room *room) {
    return (room->get_id() == 0);
}

int main(void)
{
    

    for (auto staff : StaffList::get_instance()->get_elements())
        delete staff;
    
    for (auto student : StudentList::get_instance()->get_elements())
        delete student;
    
    for (auto course : CourseList::get_instance()->get_elements())
        delete course;
    
    for (auto room : RoomList::get_instance()->get_elements())
        delete room;

    return 0;
}