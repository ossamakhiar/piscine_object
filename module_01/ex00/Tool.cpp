#include "Tool.hpp"

// TODO :: implementing the subject methods
// * Attach an observer to the subject (enabling the observer to listen or be prepared to receive events triggered by the subject).
void    Tool::attach(Worker* observer)
{
    if (this->worker)
    {
        // Notify the current observer that it's being replaced
        this->notify();
        // this->detach();
    }
    worker = observer;
}

void    Tool::detach()
{
    // ? unregister the observer from the subject
    worker = NULL;
}

// * Notify the observer of changes in the subject's state (specifically when the Shovel object is taken away from the Worker object).
void    Tool::notify()
{
    if (!this->worker)
        return ;
    this->worker->update(this);
}
