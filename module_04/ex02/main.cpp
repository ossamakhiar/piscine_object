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
    Headmaster  *headmaster = new Headmaster("Alan walker");
    Secretary   *secretary1 = new Secretary("julia brian");
    StaffList::get_instance()->add_element(secretary1);
    StaffList::get_instance()->add_element(headmaster);

    NeedMoreClassRoomForm   *classroom_form = dynamic_cast<NeedMoreClassRoomForm*>(secretary1->createForm(FormType::NeedMoreClassRoom));
    NeedCourseCreationForm    *course_creation = dynamic_cast<NeedCourseCreationForm*>(secretary1->createForm(FormType::NeedCourseCreation));
    course_creation->set_course_name("Introduction to dynamic programming (dp)");

    headmaster->receiveForm(classroom_form);
    headmaster->receiveForm(course_creation);
    headmaster->signForms();
    headmaster->executeForms();

    Classroom   *classroom1 = classroom_form->get_classroom();

    Student     *oussama = new Student("oussama khiar");
    Student     *zayn = new Student("zayn malik");
    StudentList::get_instance()->add_element(oussama);
    StudentList::get_instance()->add_element(zayn);


    SubscriptionToCourseForm    *subscription_form = dynamic_cast<SubscriptionToCourseForm*>(secretary1->createForm(FormType::SubscriptionToCourse));
    SubscriptionToCourseForm    *subscription_form_zayn = dynamic_cast<SubscriptionToCourseForm*>(secretary1->createForm(FormType::SubscriptionToCourse));
    subscription_form->set_course(course_creation->get_course());
    subscription_form->set_student(oussama);
    subscription_form_zayn->set_course(course_creation->get_course());
    subscription_form_zayn->set_student(zayn);

    headmaster->receiveForm(subscription_form);
    headmaster->receiveForm(subscription_form_zayn);
    headmaster->signForms();
    headmaster->executeForms();

    classroom1->assignCourse(course_creation->get_course());
    oussama->attendClass(classroom1);

    std::cout << oussama->get_name() << " attend to the course " << course_creation->get_course()->get_name();
    std::cout << " " << oussama->get_attendance_nums(course_creation->get_course()) << " time \n";

    delete course_creation;
    delete subscription_form;
    delete subscription_form_zayn;
    delete classroom_form;

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