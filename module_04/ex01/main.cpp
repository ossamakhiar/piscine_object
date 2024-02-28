#include "Person.hpp"
#include "Staff.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Form.hpp"
#include "Singletons.hpp"
#include <thread>

void addStudents() {
    for (int i = 0; i < 5; ++i) {
        StudentList::get_instance()->add_element(new Student("oussama"));
    }
}

int main(void)
{
    // // SingletonDerived<Student *>::get_instance();

    // // Add elements to singleton lists
    // StudentList::get_instance()->add_element(new Student("oussama"));
    // StaffList::get_instance()->add_element(new Staff("Scar"));
    // CourseList::get_instance()->add_element(new Course("Introduction to Algorithms"));
    // RoomList::get_instance()->add_element(new Room());
    // RoomList::get_instance()->add_element(new Room());

    // // Retrieve elements from singleton lists
    // const auto& students = StudentList::get_instance()->get_elements();
    // const auto& staffMembers = StaffList::get_instance()->get_elements();
    // const auto& courses = CourseList::get_instance()->get_elements();
    // const auto& rooms = RoomList::get_instance()->get_elements();

    // // Display the number of elements in each list
    // std::cout << "Number of students: " << students.size() << std::endl;
    // std::cout << "Number of staff members: " << staffMembers.size() << std::endl;
    // std::cout << "Number of courses: " << courses.size() << std::endl;
    // std::cout << "Number of rooms: " << rooms.size() << std::endl;

    // return (0);


    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(addStudents);
    }
    for (auto& thread : threads) {
        thread.join();
    }

    const auto& students = StudentList::get_instance()->get_elements();
    std::cout << "Number of students: " << students.size() << std::endl;

    for (auto student: students)
        delete student;

    delete StudentList::get_instance();

    return 0;
}