#include "Worker.hpp"

Worker::Worker(const Position& crd, const Statistic& st)
{
    this->coordonnee = crd;
    this->stat = st;
    this->shovel = NULL;

    std::cout << "A new Worker has joined. Coordinates and statistics have been initialized.\n";
}

Worker::~Worker()
{
    std::cout << "worker is leaving. Coordinates and statistics are going out with it.\n";
    // ? When a Worker is destroyed, its components (coordinates and statistics) are also destroyed.
}

Position    Worker::get_cords() const
{
    return (this->coordonnee);
}

Statistic   Worker::get_stat() const
{
    return (this->stat);
}

void    Worker::set_cords(const Position& cords)
{
    this->coordonnee = cords;
}

void    Worker::set_stat(const Statistic& st)
{
    this->stat = st;
}

void    Worker::set_shovel(Shovel *shovel)
{
    if (!shovel)
        throw std::runtime_error("shovel pointer is null");
    this->shovel = shovel;
}

void    Worker::use_shovel()
{
    if (!shovel)
        throw std::runtime("the worker doesn't have a shovel");
    shovel->use();
    std::cout << "shovel used by the worker\n";
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
