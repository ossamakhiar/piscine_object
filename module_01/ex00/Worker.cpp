#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

Worker::Worker(const std::string& name, const Position& crd, const Statistic& st)
{
	this->name = name;
    this->coordonnee = crd;
    this->stat = st;

    std::cout << "A new Worker has joined. Coordinates and statistics have been initialized.\n";
}

Worker::~Worker()
{
    std::cout << "worker is leaving. Coordinates and statistics are going out with it.\n";
    // ? When a Worker is destroyed, its components (coordinates and statistics) are also destroyed.

    // ! i should detach the worker from the tool subject
    for (std::set<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
        (*it)->detach();
}

Position    Worker::get_cords() const
{
    return (this->coordonnee);
}

Statistic   Worker::get_stat() const
{
    return (this->stat);
}

std::string Worker::get_name() const
{
    return (this->name);
}

void    Worker::set_cords(const Position& cords)
{
    this->coordonnee = cords;
}

void    Worker::set_stat(const Statistic& st)
{
    this->stat = st;
}

bool    Worker::is_shovel(Tool *tool)
{
    return (dynamic_cast<Shovel *>(tool) != NULL);
}

bool    Worker::is_hammer(Tool *tool)
{
   return (dynamic_cast<Hammer *>(tool) != NULL);
}

void    Worker::take_tool(Tool *tool)
{
    std::string tool_name = "unknown";

    if (!tool)
        throw std::runtime_error("Bad tool address");
    tool->attach(this);
    tools.insert(tool);
    if (is_shovel(tool))
        tool_name = "Shovel";
    else if (is_hammer(tool))
        tool_name = "Hammer";
    std::cout << "The worker " << ORANGE << name << WHITE << " take a " << tool_name << "\n";
}

void    Worker::use_tool(Tool *tool)
{
    if (tools.size() == 0 || tools.count(tool) == 0)
        throw std::runtime_error(std::string("the worker ") + ORANGE + name + WHITE + " doesn't have this tool");

    std::cout << ORANGE << name << WHITE << ": ";
    tool->use();
}

// get notified by the shovel (subject) to break the relationship
void    Worker::update(Tool *tool)
{
    std::string tool_name = "unknown";

    if (tools.size() == 0)
        return ;
    tools.erase(tool);

    // informing that the relationship broken
    if (is_shovel(tool))
        tool_name = "Shovel";
    else if (is_hammer(tool))
        tool_name = "Hammer";
    std::cout << "the Tool " << tool_name << " has been taken from the worker " << ORANGE << name << WHITE << ".\n";
}


void	Worker::workshop_subscribing(Workshop *workshop)
{
    if (workshop == NULL || workshop.count(workshop) == 1)
        return ;
    try {
        workshop->signup(this);
        workshops.insert(workshop);
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
}

void	Worker::workshop_unsubscribing(Workshop *workshop)
{
    if (workshop == NULL || workshops.count(workshop) == 0)
        return ;

    workshop->unregister(this);
    workshops.erase(workshop);
    std::cout << ORANGE << name << WHITE << " unregister from a workshop\n";
}



std::ostream& operator<<(std::ostream& os, const Worker& worker)
{
    std::string         separator_line(43, '-'), cords_line, stat_line;
    Position            cords = worker.get_cords();
    Statistic           stat = worker.get_stat();

    std::stringstream   ss;
    ss << "Coordinates: (" << cords.x << ", " << cords.y << ", " << cords.z << ")";
    cords_line = ss.str();
    ss.str("");
    ss << "Statistics: Level: " << stat.level << ", Experience: " << stat.exp;
    stat_line = ss.str();

    os << "+" << separator_line << "+\n"
       << "|" << std::setw(separator_line.length()) << std::left << "Worker Information" << "|\n"
       << "+-------------------------------------------+\n"
       << "|" << std::setw(separator_line.length()) << std::left << cords_line << "|\n"
       << "|" << std::setw(separator_line.length()) << stat_line << "|\n"
       << "+-------------------------------------------+";

    return os;
}
