#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

#include <iostream>

class Employee
{
private:
    int hourlyValue;

public:
    Employee(int hourly_value) : hourlyValue(hourly_value) {

    };
    virtual ~Employee() {}

    virtual int executeWorkday() = 0;
};


#endif