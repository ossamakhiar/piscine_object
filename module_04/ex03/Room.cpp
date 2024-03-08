#include "Room.hpp"

long long Room::_id_counter = 0;

// ...

void    Room::printOccupant()
{
    // ....
    std::cout << "Occupants in Room " << ID << ": [";
    for (auto occupant : _occupants)
        std::cout << occupant->get_name() << ", ";
    std::cout << "]\n";
}