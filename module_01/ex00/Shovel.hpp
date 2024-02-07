#ifndef SHOVEL_HPP
# define SHOVEL_HPP

#include <iostream>
#include "Tool.hpp"

class Worker;

class   Shovel : public Tool
{
private:
    int		numberOfUses;
    Worker	*worker; // the subject have only one observer
    // Pointer to the current owner of the shovel. When this pointer changes, 
    // it serves as a notification that the shovel's state has changed,
    // indicating that the tool is no longer in use by the previous owner.

	// ! Prohibited from copying...
	Shovel(const Shovel&);
	Shovel& operator=(const Shovel&);

public:
    Shovel();
    ~Shovel();

    // * Subject interface implementation
    void    attach(Worker* observer);
    void    detach(); // ! not used
    void    notify();

    void    use();

    // ? accessor
    int get_nou();
};

#include "Worker.hpp"

/**
 ** the tool should notify its worker that is has been assigned to another worker, 
 ** and a worker should forget about a tool notifying it has been assigned somewhere else
*/

#endif