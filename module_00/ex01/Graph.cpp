#include "Graph.hpp"


// ! maybe it should be a single dimenssion array and they store the point
// ! when it can to printing search for if the current position is sat
Graph::Graph(Vector2 s) : size(s)
{
    for (int y = 0; y < (int)size.get_y(); y++)
    {
        std::vector<Vector2>    row;
        for (int x = 0; x < (int)size.get_x(); x++)
            row.push_back(Vector2());
        this->graph.push_back(row);
    }
}

Graph::Graph(const Graph& g)
{
    this->size = g.size;
    this->graph = g.graph;
}

Graph& Graph::operator=(const Graph& rhs)
{
    if (this == &rhs)
        return (*this);
    this->size = rhs.size;
    this->graph = rhs.graph;
    return (*this);
}

Graph::~Graph()
{

}

void    add_point(const Vector2& v)
{
    (void)v;
}


std::ostream&   operator<<(std::ostream& os, const Graph& g)
{
    for (std::vector<std::vector<Vector2 > >::const_reverse_iterator rit = g.graph.rbegin(); rit != g.graph.rend(); ++rit)
    {
        std::vector<Vector2>    row = *rit;
        for (std::vector<Vector2>::iterator it = row.begin(); it != row.end(); ++it)
            std::cout << ((it->get_x() >= 1) ? "X" : ".") << "  ";
        std::cout << "\n";
    }
    return (os);
}