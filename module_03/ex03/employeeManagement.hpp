#ifndef EMPLOYEE_MANAGEMENT_HPP
# define EMPLOYEE_MANAGEMENT_HPP

#include <set>
#include <iostream>
#include "employee.hpp"

class EmployeeManagement
{
private:
    std::set<Employee *>  employees;

public:
    EmployeeManagement() {

    }
    ~EmployeeManagement() {

    }

    void    addEmployee(Employee* employee) {
        if (!employee)
            return ;
        employees.insert(employee);
    }

    void    removeEmployee(Employee* employee) {
        if (!employee)
            return ;
        employees.erase(employee);
    }

    void executeWorkday() {
        for (std::set<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it)
            (*it)->executeWorkday();
    }

    void    calculatePayroll() {
        for (std::set<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it)
        {
            (*it)->executeWorkday(); // print paying
        }
    }
};



#endif