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

public:
	virtual ~Tool() {};

	virtual void	use() = 0;
	virtual void    attach(Worker* observer) = 0;
    virtual void    detach() = 0; // ! not used
    virtual void    notify() = 0;
};

#endif