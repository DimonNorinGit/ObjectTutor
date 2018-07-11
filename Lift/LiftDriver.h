#include"api.h"
#include<queue>
#include"Cabin.h"

class Driver{

	int PassengersInDay;
	int floor_count;
	int curr_floor;
	int curr_goal;
	bool isEmpty;
	std::queue<int> calls_lift;
	std::queue<int> commands_lift;

public:

	Driver(int floor_c);

	int getCurrentFloor();

	LiftState executeNextCommand(std::vector< std::pair< PeopleGroup* , int > >& floors_group , std::multimap<int , PeopleGroup*>& passengers);

	LiftState executeCommandInLift(std::vector< std::pair< PeopleGroup* , int > >& floors_group , std::multimap<int , PeopleGroup*>& passengers);

	LiftState executeCallCommand();

	void addToCalls(int floor);

	void addToCommands(int floor);

};