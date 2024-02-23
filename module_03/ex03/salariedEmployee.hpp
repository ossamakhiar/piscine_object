#ifndef SLARIED_EMPLOYEE_HPP
# define SLARIED_EMPLOYEE_HPP

#include <iostream>
#include "employee.hpp"

class ContractEmployee : public Employee 
{
private:
    int absent_hours;

public:
    ContractEmployee(int hourly_value) : Employee(hourly_value), absent_hours(0) {

    }

    ~ContractEmployee() {}

    void    registerAbsentHour(int absent) {
        absent_hours += absent;
    }
};

class Apprentice : public Employee
{
private:
    /*data*/

public:
    Apprentice(int hourly_value) : Employee(hourly_value) {

    }

    ~Apprentice() {

    }

    void    registerAbentHour(int hour) {

    }

    void    registerSchoolHour(int hour) {

    }
};

#endif