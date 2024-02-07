#ifndef IOBSERVER_HPP
# define IOBSERVER_HPP

#include <iostream>

class IObserver
{
public:
    virtual ~IObserver() {};
    virtual void   update(void *subject, const std::string& msg) = 0;
};

#endif