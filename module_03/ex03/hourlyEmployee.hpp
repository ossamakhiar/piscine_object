#ifndef HOURLY_EMPLOYEE_HPP
# define HOURLY_EMPLOYEE_HPP

#include <iostream>
#include "employee.hpp"

// !! Maybe i should extend the interface Employee >>
/*
class ITempWorker : public Employee
{
public:
    virtual void    registerWorkedHours(int hours) = 0;
}
*/

class   TempWorker : public Employee
{
private:
    int work_hours;

public:
    TempWorker(int hourly_value) : Employee(hourly_value), work_hours(0) {

    }

    ~TempWorker() {

    }

    void    registerWorkedHours(int hours) {
        work_hours += hours;
    }

    int    executeWorkday() {
        return (work_hours);
    }
};



#endif