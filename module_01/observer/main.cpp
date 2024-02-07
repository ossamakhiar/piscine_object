#include "Observer.hpp"
#include "Subject.hpp"


int main(void)
{
    Observer    tool;
    Subject     worker;

    worker.attach(&tool);
    worker.notify();

    return (0);
}