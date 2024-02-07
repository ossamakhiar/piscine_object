#include "Worker.hpp"

Worker::Worker(const std::string& name, const Position& crd, const Statistic& st)
{
	this->name = name;
    this->coordonnee = crd;
    this->stat = st;
    this->shovel = NULL;

    std::cout << "A new Worker has joined. Coordinates and statistics have been initialized.\n";
}

Worker::~Worker()
{
    std::cout << "worker is leaving. Coordinates and statistics are going out with it.\n";
    // ? When a Worker is destroyed, its components (coordinates and statistics) are also destroyed.

    // ! i should detach the worker from the tool subject
    // this->tools
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

void    Worker::take_tool(Tool *tool)
{
    if (!tool)
        throw std::runtime_error("Bad tool address");
    tool->attach(this);
    tools.push_back(tool);
}

void    Worker::use_tool()
{
    // ! should i use all tools
}

// void    Worker::take_shovel(Shovel *shovel)
// {
//     if (!shovel)
//         throw std::runtime_error("shovel pointer is null");
//     this->shovel = shovel;
//     shovel->attach(this);// attach or register the this worker (observer) to the Shovel (subject) 
// 	std::cout << "the worker " << ORANGE << name << WHITE << " take a shovel\n";
// }

// void    Worker::use_shovel()
// {
//     if (!shovel)
//         throw std::runtime_error(std::string("the worker ") + ORANGE + name + WHITE + " doesn't have a shovel");
//     shovel->use();
//     std::cout << "shovel used by the worker " << ORANGE << name << WHITE << "\n";
// }

// get notified by the shovel (subject) to break the relationship
void    Worker::update(Tool *tool)
{
    if (!tools.size() == 0)
        return ;
    tools.remove(tool);
    // this->shovel = NULL;
    // std::cout << "The shovel has been taken from the worker " << ORANGE << name << WHITE << ".\n";
}


// void    Worker::update()
// {
//     if (!shovel)
//         return ;
//     this->shovel = NULL;
//     std::cout << "The shovel has been taken from the worker " << ORANGE << name << WHITE << ".\n";
// }




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
