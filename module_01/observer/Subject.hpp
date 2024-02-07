#ifndef SUBJECT_HPP
# define SUBJECT_HPP

#include "ISubject.hpp"

class Subject : public ISubject
{
private:
    IObserver   *obs;
public:
    void    attach(IObserver *observer)
    {
        obs = observer;
    }

    void    detach(IObserver *ignore)
    {
        obs = NULL;
        (void)ignore;
    }

    void    notify()
    {
        obs->update(this, "Hello brother");
    }

    void take_tool(IObserver* t)
    {
        
    }
};

#endif