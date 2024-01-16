#ifndef GRAPH_HPP
# define GRAPH_HPP

#include "Vector2.hpp"
#include <iostream>
#include <vector>

class Graph
{
private:
    Vector2								size;
    std::vector<std::vector<Vector2> >  graph;

public:
    Graph(Vector2 s);
    Graph(const Graph& graph);
    Graph& operator=(const Graph& rhs);
    ~Graph();

    void    add_point(const Vector2& v);

    friend  std::ostream&   operator<<(std::ostream& os, const Graph& g);
};

#endif