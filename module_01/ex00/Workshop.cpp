#include "Workshop.hpp"

Workshop::Workshop() : tool_required("")
{
}

void    Workshop::signup(Worker *worker)
{
    if (worker == NULL || workers_list.count(worker) == 1)
        return ;
    if (tool_required != "" && !worker.has_tool(tool_required))
        throw std::runtime_error(std::string("Worker should have ") + tool_required + " Tool to join this workshop")
    workers_list.insert(worker);
    worker->workshop_subscribing(this);
    std::cout << ORANGE << worker->get_name() << WHITE << " join the a workshop\n";
}


void    Workshop::unregister(Worker *worker)
{
    if (workers_list.count(worker) == 0)
        return ;
    
    workers_list.erase(worker);
    worker->workshop_unsubscribing(this);
    std::cout << ORANGE << worker->get_name() << WHITE << "  the a workshop\n";
}