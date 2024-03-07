#ifndef STAFF_LIST_HPP
# define STAFF_LIST_HPP

#include "Staff.hpp"
#include "Headmaster.hpp"
#include "Singletons.hpp"

class	StaffList : public Singleton<Staff *>
{
private:
	StaffList();

public:
	static	Headmaster* getHeadmaster() {
		for (auto staff : get_instance()->get_elements())
			if (dynamic_cast<Headmaster*>(staff))
				return dynamic_cast<Headmaster*>(staff);
		return (nullptr);
	}

	static	Secretary* get_secretary() {
		for (auto staff : get_instance()->get_elements())
			if (dynamic_cast<Secretary*>(staff))
				return dynamic_cast<Secretary*>(staff);
		return (nullptr);
	}
};

#endif