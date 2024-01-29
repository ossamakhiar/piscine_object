#include "Graph.hpp"

int main(void)
{
    Vector2 size(10, 10);
    Graph   g(size);

    g.add_point(Vector2(5, 5));
    g.add_point(Vector2(0, 0));
	g.add_point(Vector2(2, 2));
	// g.add_point(Vector2(4, 2));
	g.add_point(Vector2(2, 4));
    // g.add_line(Vector2(0, 0), Vector2(5, 5));

    std::cout << g << "\n";
    g.save_as_png("graph.png");
    return (0);
}