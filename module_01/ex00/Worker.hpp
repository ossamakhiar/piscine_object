#ifndef WORKER_HPP
# define WORKER_HPP

#include <set>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"


# define ORANGE "\e[1;33m"
# define WHITE "\e[0m"

class IWorkshop;

class Worker
{
private:
	std::string	name;

	Position    coordonnee;
	Statistic   stat;
	// ! The Worker must now be able to have multiple tools simultaneously
	std::set<Tool *> tools; // aggregation relationship each object in this relationship has its own life-cycle

	std::set<IWorkshop *>	workshops;


	Worker();

	// ! helpers
	bool    is_shovel(Tool *tool);
	bool    is_hammer(Tool *tool);

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
	void	work(Tool *tool); // ? since the worker have multiple tools, it is essential for them to know which tool should be used.

	void	workshop_subscribing(IWorkshop *);
	void	workshop_unsubscribing(IWorkshop *);

	template <typename T>
	T	*getTool() {
		T	*ret = NULL;

		for (std::set<Tool *>::iterator it = tools.begin();it != tools.end(); ++it)
			if ((ret = dynamic_cast<T *>((*it))))
				return (ret);
		return (NULL);
	}

	friend  std::ostream& operator<<(std::ostream& os, const Worker& worker);
};

#include "Workshop.hpp"


// * an object is an entity that has state (properies), behavior (operations), identity (type)...
// * the behavior of an object is influenced by its history (state)
/**
 ** object plus the current (usually dynamic) values of each of these properties
 *? state:
 ** The state of an object encompasses all of the (usually static) properties of the object

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