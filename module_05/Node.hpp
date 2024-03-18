#ifndef NODE_HPP
# define NODE_HPP

#include <string>

class Node
{
private:
	std::string name;

public:
	Node() {}
	Node(const std::string& data) : name(data) {}
	~Node() {}

	std::string get_unique_data() const {
		return (name);
	}
};




#endif