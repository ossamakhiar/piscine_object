#ifndef TOOL_HPP
# define TOOL_HPP

#include <iostream>

class Worker;

/**
 * @brief Abstract class for tools like Shovel, Hammer, etc.
 * @details This abstract class defines the common interface for various tools.
 *          Concrete tool classes should inherit from this class and provide
 *          their own implementation for the use method.
 *          It also provides an interface for attaching, detaching, and notifying
 *          observers (Workers) who are interested in tool-related events.
 */
class Tool
{
protected:
	int numberOfUses;
	Worker	*worker; // the subject have only one observer
					// Pointer to the current owner of the shovel. When this pointer changes, 
				   // it serves as a notification that the shovel's state has changed,
				  // indicating that the tool is no longer in use by the previous owner.

public:
	Tool() : numberOfUses(0), worker(NULL) {}
	virtual ~Tool() {};

	virtual void	use() = 0;
	virtual void    attach(Worker* observer);
    virtual void    detach(); // ! not used
    virtual void    notify();
};

#include "Worker.hpp"

/**
 ** the tool should notify its worker that is has been assigned to another worker, 
 ** and a worker should forget about a tool notifying it has been assigned somewhere else
*/

#endif