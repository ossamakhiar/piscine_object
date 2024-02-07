#ifndef ISUBJECT_HPP
# define ISUBJECT_HPP

#include <iostream>
#include "IObserver.hpp"

class ISubject
{
public:
    virtual ~ISubject() {};
    virtual void    attach(IObserver* observer) = 0;
    virtual void    detach(IObserver* observer) = 0;
    virtual void    notify() = 0;
};


#endif