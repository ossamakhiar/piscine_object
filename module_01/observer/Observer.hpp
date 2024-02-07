#ifndef OBSERVER_HPP
# define OBSERVER_HPP

#include "IObserver.hpp"

class Observer : public IObserver
{
private:


public:
    void update(void *subject, const std::string& msg)
    {
        std::cout << msg << "\n";
        (void)subject;
    }

};

#endif