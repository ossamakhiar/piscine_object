#include "Shovel.hpp"

Shovel::Shovel() : numberOfUses(0), worker(NULL)
{
    std::cout << "Shovel constructed\n";
}

Shovel::~Shovel()
{
    std::cout << "Shovel has destroyed\n";
    this->notify();
}

void    Shovel::use()
{
    numberOfUses++;
    std::cout << "Shovel has been used " << numberOfUses << " times.\n";
}


// TODO :: implementing the subject methods
// * Attach an observer to the subject (enabling the observer to listen or be prepared to receive events triggered by the subject).
void    Shovel::attach(Worker* observer)
{
    if (this->worker)
    {
        // Notify the current observer that it's being replaced
        this->notify();
        // this->detach();
    }
    worker = observer;
}

// * Notify the observer of changes in the subject's state (specifically when the Shovel object is taken away from the Worker object).
void    Shovel::notify()
{
    if (!this->worker)
        return ;
    this->worker->update(this);
}

void    Shovel::detach()
{
    // ? unregister the observer from the subject
    worker = NULL;
}


// ? accessor
int Shovel::get_nou()
{
    return (numberOfUses);
}