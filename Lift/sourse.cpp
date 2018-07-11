#include<iostream>
#include"PeopleGroup.h"
#include<vector>
#include<map>
#include"api.h"
#include<cstdlib>
#include<ctime>
#include<queue>

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


PeopleGroup* generateNewPeopleGroup(){


}


int main(){			
	const int rand_range = 12000;
	const int rand_factor = 3;
	const int floor_count = 10;
	const int max_weight = 400;

	Lift* lift = new Lift(max_weight , floor_count); 
	LiftShaft* lift_shaft = new LiftShaft(floor_count);
	std::vector<bool> isfloor_full(floor_count);//fill(false)
	
	PeopleGroup* new_group = nullptr;
	int work_time  = 100;
	for(int floor = 1; floor <= floor_count; ++floor){
			srand(time(0));
			if(((rand() % 12000 ) % rand_factor) == 0 && !isfloor_full[floor]){
				new_group = new PeopleGroup(floor_count , floor);
				lift_shaft->setFloorGroup(floor , new_group);
				isfloor_full[floor] = true;
			}
			if(new_group){
				std::cout << "G:" << floor <<"->"<< new_group->getGoalFloor() << std::endl;
				lift->sendSignalToDriver(floor);
			}
			new_group = nullptr;
	}
	while(work_time--){

		srand(time(0));

		lift->work(*lift_shaft , isfloor_full);

		std::cout<<"L:"<<lift->getCurrentFloor() << std::endl;

		//PeopleGroup* new_group = nullptr;

		/*for(int floor = 1; floor <= floor_count; ++floor){
			srand(time(0));
			if(((rand() % 12000 ) % rand_factor) == 0 && !isfloor_full[floor]){
				new_group = new PeopleGroup(floor_count , floor);
				lift_shaft->setFloorGroup(floor , new_group);
				isfloor_full[floor] = true;
			}
			if(new_group){
				std::cout << "G:" << floor <<"->"<< new_group->getGoalFloor() << std::endl;
				lift->sendSignalToDriver(floor);
			}
			new_group = nullptr;
		}*/


	}



	
	return 0;
}