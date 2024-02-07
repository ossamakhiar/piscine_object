#ifndef WORKER_HPP
# define WORKER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <set>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"


# define ORANGE "\e[1;33m"
# define WHITE "\e[0m"

class Worker
{
private:
	std::string	name;

	Position    coordonnee;
	Statistic   stat;
	// ! The Worker must now be able to have multiple tools simultaneously
	std::set<Tool *> tools;
	// Tool		*tool; // aggregation relationship each object in this relation has its own life-cycle

	Worker();

public:

	Worker(const std::string& name, const Position& crd, const Statistic& st);
	~Worker();

	// ? setters
	void    set_cords(const Position& cords);
	void    set_stat(const Statistic& st);

	// ? getters
	Position	get_cords() const;
	Statistic	get_stat() const;
	std::string	get_name() const;

	void	update(Tool *tool);

	void    take_tool(Tool *tool);
	void    use_tool();

	// void    take_shovel(Shovel *shovel);
	// void    use_shovel();

	friend  std::ostream& operator<<(std::ostream& os, const Worker& worker);
};


// * an object is an entity that has state (properies), behavior (operations), identity (type)...
// * the behavior of an object is influenced by its history (state)
/**
 ** object plus the current (usually dynamic) values of each of these properties
 *? state:
 ** The state of an object encompasses all of the (usually static) properties of the

 *? behavior:
 ** Behavior is how an object acts and reacts, in terms of its state changes and message passing

 *? identity:
 ** ...

 a message is simply an operation that one object performs on another

 **Whereas an object is a concrete entity that exists in time and space, 
 **a class represents only an abstraction, the “essence” of an object, as it were.

 **Friendships break a class’s encapsulation and so, as in life, must be chosen carefully

	back to page 101
	
*/

#endif