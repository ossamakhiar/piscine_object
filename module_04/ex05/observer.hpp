#ifndef OBSERVER_HPP
# define OBSERVER_HPP

#include "Event.hpp"

class Observer
{
private:

public:
    virtual void update(Event event) = 0;
    virtual ~Observer() {}
};


#endif