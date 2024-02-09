#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

#include "Worker.hpp"
#include <map>

template <typename T>
class Workshop
{
private:
    std::map<Worker *, T *>  workers_list;
    // std::string         tool_required;
    /* data */

public:
    Workshop(const std::string& t) {}
    ~Workshop() {}

    void    signup(Worker *worker);
    void    unregister(Worker *worker);

};

#endif