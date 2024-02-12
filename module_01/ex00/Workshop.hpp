#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

#include <set>
#include <typeinfo>
#include "Worker.hpp"
#include "IWorkshop.hpp"

template <typename T>
class Workshop : public IWorkshop
{
private:
    std::set<Worker *>  workers_list;
    // std::string         tool_required; // bad idea
    /* data */

public:
    Workshop() {
        const std::type_info& ti1 = typeid(T);
        std::cout << "a new Workshop of type " << ti1.name() << "\n";
    };
    ~Workshop() {
        std::cout << "Workshop destructed\n";
    }

    void    signup(Worker *worker)
    {
        if (worker == NULL || workers_list.count(worker) == 1)
            return ;
        if (!worker->getTool<T>())
            throw std::runtime_error(std::string("Worker should have the required Tool to join this workshop"));
        workers_list.insert(worker);
        worker->workshop_subscribing(this);
    }

    void    unregister(Worker *worker)
    {
        if (workers_list.count(worker) == 0)
            return ;
        workers_list.erase(worker);
        worker->workshop_unsubscribing(this);
    }

    void    tool_loosed(Worker *worker)
    {
        if (worker->getTool<T>())
            return ;
        workers_list.erase(worker);
        worker->workshop_unsubscribing(this);
    }

    void    executeWorkDay() {
        std::cout << "Workshop executing work of the day🛠️\n";
        for (std::set<Worker *>::iterator it = workers_list.begin(); it != workers_list.end(); ++it)
            (*it)->work((*it)->getTool<T>());
    }
};

#endif