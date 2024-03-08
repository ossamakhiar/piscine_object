#ifndef ROOM_LIST_HPP
# define ROOM_LIST_HPP

#include "../Room.hpp"
#include "../Singletons.hpp"

class	RoomList : public Singleton<Room*>
{
private:
	RoomList();

public:
	// Nothing special

	static Classroom	*get_free_classroom() {
		for (auto room : get_instance()->get_elements())
			if (Classroom* classroom = dynamic_cast<Classroom*>(room))
				if (classroom->free())
					return classroom;
		return (nullptr);
	}

	static SecretarialOffice	*get_secretary_office() {
		for (auto room : get_instance()->get_elements())
			if (SecretarialOffice* sec_office = dynamic_cast<SecretarialOffice*>(room))
					return sec_office;
		return (nullptr);
	}
};

#endif