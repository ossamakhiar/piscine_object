#ifndef RAILWAY_HPP
# define RAILWAY_HPP

#include <stdexcept>


template<typename Node, typename WType = double>
class Edge
{
private:
	Node	*dest;
	WType	weight;

public:
	Edge() : dest(nullptr) {}

    Edge(Node* p_dest, WType p_weight) : dest(p_dest), weight(p_weight) {
        if (!p_dest)
            throw std::invalid_argument("Destination node cannot be null.");
    }
	~Edge() {}

	Node    *get_destination() const {
		return (dest);
	}

	WType  get_weight() const {
		return (weight);
	}

	void    set_destination(Node *p_dest) {
		if (!p_dest)
			return ;
		dest = p_dest;
	}

	void    set_weight(WType p_weight) {
		this->weight = p_weight;
	}
};


#endif