#ifndef WORKER_HPP
# define WORKER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"


class Worker
{
private:
    Position    coordonnee;
    Statistic   stat;
    Shovel      *shovel;

public:
    Worker(const Position& crd, const Statistic& st);
    ~Worker();

    // ? setters
    void    set_cords(const Position& cords);
    void    set_stat(const Statistic& st);
    void    set_shovel(Shovel *shovel);

    // ? getters
    Position    get_cords() const;
    Statistic   get_stat() const;

    void    use_shovel();

    friend  std::ostream& operator<<(std::ostream& os, const Worker& worker);
};


// * an object is an entity that has state (properies), behavior (operations), identity (type)...
// * the behavior of an object is influenced by its history (state)
/**
 *? state:
 ** The state of an object encompasses all of the (usually static) properties of the
 ** object plus the current (usually dynamic) values of each of these properties

 *? behavior:
 ** Behavior is how an object acts and reacts, in terms of its state changes and message passing

 *? identity:
 ** ...

 a message is simply an operation that one object performs on another

 **Whereas an object is a concrete entity that exists in time and space, 
 **a class represents only an abstraction, the “essence” of an object, as it were.

 **Friendships break a class’s encapsulation and so, as in life, must be chosen carefully

*/

#endif