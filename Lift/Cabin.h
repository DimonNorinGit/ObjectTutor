#include<map>
#include"PeopleGroup.h"


class Cabin{

	int max_weight;
	int curr_weight;
	std::multimap<int , PeopleGroup*> passengers_group;

public:

	Cabin(int max_w);

	int addPassengersGroup(PeopleGroup* group);

	PeopleGroup* removePassengersGroup(int exit_floor);

	std::multimap<int , PeopleGroup*>& getPassengers();

};