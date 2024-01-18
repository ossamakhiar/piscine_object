#ifndef GRAPH_HPP
# define GRAPH_HPP

#include "Vector2.hpp"
#include "MyRuntimeError.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

class Graph
{
private:
    Vector2								size;
    std::vector<Vector2>                points;
    std::vector<std::pair<Vector2, Vector2> >                lines;
    // std::vector<std::vector<Vector2> >  graph;

    bool    point_occupied(const Vector2& p) const;

    bool	cross_line(int col, int row) const; 

public:
    Graph(Vector2 s);
    Graph(const Graph& graph);
    Graph& operator=(const Graph& rhs);
    ~Graph();

    void    add_point(const Vector2& v);
    void	add_line(const Vector2& start, const Vector2& end);
    void    read_input_points(const std::string& file_path);

    friend  std::ostream&   operator<<(std::ostream& os, const Graph& g);
};

#endif