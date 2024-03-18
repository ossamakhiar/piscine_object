#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <assert.h>
#include "Edge.hpp"

template<typename Node, typename WType = double>
class Graph
{
private:
	typedef std::list<Edge<Node, WType> *>	EdgeList;
	std::unordered_map<Node*, std::list<Edge<Node, WType> *>>  adjacencyList;



private: // private methods
	typename EdgeList::iterator findEdgeIterator1(EdgeList& edgelist, Node *dest) {
		for (auto it = edgelist.begin(); it != edgelist.end(); ++it) {
			if ((*it)->get_destination() == dest) {
				return it;
			}
		}
		assert(0);
		return edgelist.end();
	}

public:
	Graph() {};

	~Graph() {
		for (auto node : adjacencyList)
		{
			for (auto edge : node.second)
				delete edge;
			node.second.clear();
		}
	};


	/**
	 * @brief Checks if an edge exists between two nodes.
	 * @param src Pointer to the source node of the edge.
	 * @param dest Pointer to the destination node of the edge.
	 * @return True if an edge exists between src and dest, false otherwise.
	 *         Returns false if either src or dest is nullptr or if src is not present in the graph.
	*/
	bool	hasEdge(Node *src, Node *dest) {
		if (!src || !dest || !adjacencyList.count(src))
			return (false);

		for (auto edge : adjacencyList[src])
			if (edge->get_destination() == dest)
				return (true);
		return (false);
	}



	/**
	 * @brief Adds a new node to the graph.
	 * @param node Pointer to the node to be added.
	 *             If nullptr or already exists in the graph, no action is taken.
	*/
	void	add_node(Node* node) {        
		if (!node || adjacencyList.count(node))
			return ;
		adjacencyList[node] = std::list<Edge<Node, WType> *>();
	}



	/**
	 * @brief Adds a new edge between existing nodes or adds missing nodes and connects them.
	 *        If the source or destination nodes are not yet added to the graph, they will be added.
	 * @param src Source node (existing or new).
	 * @param dest Destination node (existing or new).
	 * @param weight Weight of the edge.
	*/
	void	add_edge(Node* src, Node* dest, WType weight) {
		if (!src || !dest)
			return ;
		// * connecting the two nodes
		adjacencyList[src].push_back(new Edge<Node, WType>(dest, weight));
		adjacencyList[dest].push_back(new Edge<Node, WType>(src, weight));
	}


	/**
	 * @brief Removes a node from the graph along with its associated edges.
	 * @param node Pointer to the node to be removed.
	 *             If nullptr or not found in the graph, no action is taken.
	*/
	void	remove_node(Node* node) {
		if (!node || !adjacencyList.count(node))
			return ;
		EdgeList	neighbors = adjacencyList[node]; // Copying to avoid access iterator after erase it 
		for (auto edge : neighbors)
			remove_edge(node, edge->get_destination());
		adjacencyList.erase(node);
	}



	/**
	 * @brief Removes an edge between two nodes.
	 * @param src Pointer to the source node of the edge.
	 * @param dest Pointer to the destination node of the edge.
	 *             If the edge doesn't exist, no action is taken.
	*/
	void remove_edge(Node *src, Node *dest) {
		if (!hasEdge(src, dest))
			return;

		// First, locate the iterator corresponding to the destination node within the list of edges associated with the source node,
		// and perform the same process for the destination node itself.
		auto srcEdgeIt = findEdgeIterator1(adjacencyList[src], dest);
		auto destEdgeIt = findEdgeIterator1(adjacencyList[dest], src);

		delete (*srcEdgeIt);
		delete (*destEdgeIt);
		adjacencyList[src].erase(srcEdgeIt);
		adjacencyList[dest].erase(destEdgeIt);
	}


	// assuming it non-cyclic graph
	void	dfs(Node *start) {
		std::queue<Node *>	q;
		std::unordered_map<Node*, bool>	visited;

		if (!start || !adjacencyList.count(start))
			return ;
		q.push(start);
			std::cout << "here\n";
		visited[start] = true;
		while (q.size() > 0) {
			Node *curr = q.front();
			q.pop();
		
			std::cout << *curr << " ";
			for (auto edge : adjacencyList[curr]) {
				if (!visited.count(edge->get_destination())) {
					// std::cout << *(edge->get_destination()) << "**";
					visited[edge->get_destination()] = true;
					q.push(edge->get_destination());
				}
			}
		}
		std::cout << "\n";
	}



	void	printGraph() {
		for (auto node : adjacencyList) {
			std::cout << *(node.first) << " -> ";
			for (auto edge : node.second)
				std::cout << *(edge->get_destination()) << ", ";
			std::cout << "\n";
		}
	}
};


#endif