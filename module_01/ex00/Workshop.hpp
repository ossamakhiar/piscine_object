#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

#include "Worker.hpp"
#include <set>

class IWorkshop
{
public:
    virtual void    signup(Worker *worker) = 0;
    virtual void    unregister(Worker *worker) = 0;
    virtual void    tool_loosed(Worker *worker) = 0;
    virtual void    executeWorkDay() = 0; // ? not nessecry to include this in the interface.
};

template <typename T>
class Workshop : public IWorkshop
{
private:
    std::set<Worker *>  workers_list;
    // std::string         tool_required; // bad idea
    /* data */

public:
    Workshop() {};
    ~Workshop() {}

    void    signup(Worker *worker)
    {
        if (worker == NULL || workers_list.count(worker) == 1)
            return ;
        if (!worker->getTool<T>())
            throw std::runtime_error(std::string("Worker should have the required Tool to join this workshop"));
        workers_list.insert(worker);
        std::cout << ORANGE << worker->get_name() << WHITE << " join a workshop\n";
    }

    void    unregister(Worker *worker)
    {
        if (workers_list.count(worker) == 0)
            return ;

        workers_list.erase(worker);
        std::cout << ORANGE << worker->get_name() << WHITE << " released from a workshop\n";
    }

    void    tool_loosed(Worker *worker)
    {
        if (worker->getTool<T>())
            return ;
        worker->workshop_unsubscribing(this);
    }

    void    executeWorkDay() {
        std::cout << "Workshop executing work of the day🛠️\n";
        for (std::set<Worker *>::iterator it = workers_list.begin(); it != workers_list.end(); ++it)
            (*it)->work((*it)->getTool<T>());
    }
};

#endif