#include"LiftShaft.h"


LiftShaft::LiftShaft(int floor_c){
	floor_count = floor_c;
	shaftFloors.resize(floor_count);///////////fill(0)
}

void LiftShaft::setFloorGroup(int floor_number , PeopleGroup* group){
	floor_number--;
	shaftFloors[floor_number].first = group;
	shaftFloors[floor_number].second = group->getGoalFloor();
}

PeopleGroup* LiftShaft::removeFloorGroup(int floor_number){
	floor_number--;
	PeopleGroup* g  = shaftFloors[floor_number].first;
	shaftFloors[floor_number].first = nullptr;
	shaftFloors[floor_number].second = 0;
	return g;
}

std::vector< std::pair< PeopleGroup* , int > >& LiftShaft::getshaftFloors(){
	return shaftFloors;
}
