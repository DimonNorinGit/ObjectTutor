#include"PeopleGroup.h"
#include<ctime>
#include<cstdlib>


PeopleGroup::PeopleGroup(int floor_count , int c_floor){

	srand(time(0));
	curr_floor = c_floor;
	goal_floor = curr_floor;

	while(curr_floor == goal_floor)
		goal_floor = (rand() % floor_count) + 1;

	people_count = (rand() % MAX_PEOPLE_IN_FLOOR) + 1;

	total_weight = 0;
	for(int i = 0; i < people_count; ++i){
		total_weight+=(rand() % MAX_PEOPLE_WEIGHT);
	}
	
}

int PeopleGroup::getWeight(){
	return total_weight;
}

int PeopleGroup::getGoalFloor(){
	return goal_floor;
}