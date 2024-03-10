#ifndef OBSERVER_HPP
# define OBSERVER_HPP

class Observer
{
private:

public:
    virtual void update() = 0;
    virtual ~Observer() {}
};


#endif