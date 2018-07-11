#include<vector>
#include"LiftDriver.h"

class LiftShaft{
	int floor_count;
	std::vector< std::pair< PeopleGroup* , int > > shaftFloors;

public:

	LiftShaft(int floor_c);

	void setFloorGroup(int floor_number , PeopleGroup* group);

	PeopleGroup* removeFloorGroup(int floor_number);

	std::vector< std::pair< PeopleGroup* , int > >& getshaftFloors();


};



class Lift{

	Driver* driver;
	Cabin* cabin;
	LiftState curr_state;
	int curr_floor;
public:

	Lift(int max_weight , int floor_count);
	

	void work(LiftShaft& lift_shaft , std::vector<bool>& isfloor_full);

	void sendSignalToDriver(int floor);

	int getCurrentFloor();
	
};