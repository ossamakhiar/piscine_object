#include "./graph/Graph.hpp"


int main(void)
{
    // Define some nodes
    int* node1 = new int(1);
    int* node2 = new int(2);
    int* node3 = new int(3);
    int* node4 = new int(4);

    // Create a graph
    Graph<int>* graph = new Graph<int>();

    // Add nodes to the graph
    graph->add_node(node4);
    graph->add_node(node3);
    graph->add_node(node2);
    graph->add_node(node1);

    // Add edges to the graph
    graph->add_edge(node1, node2, 10.0);
    graph->add_edge(node1, node3, 15.0);
    graph->add_edge(node2, node4, 15.0);
    graph->add_edge(node4, node3, 15.0);

    // graph->printGraph();
    graph->dfs(node1);


    // graph->remove_node(node1);

    // graph->printGraph();

    delete graph;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return (0);
}