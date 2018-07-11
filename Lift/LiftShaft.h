#include"PeopleGroup.h"
#include<vector>

class LiftShaft{
	
	int floor_count;
	std::vector< std::pair< PeopleGroup* , int > > shaftFloors;

public:

	LiftShaft(int floor_c);

	void setFloorGroup(int floor_number , PeopleGroup* group);

	PeopleGroup* removeFloorGroup(int floor_number);

	std::vector< std::pair< PeopleGroup* , int > >& getshaftFloors();
};