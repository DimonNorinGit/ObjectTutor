#include"Cabin.h"

Cabin::Cabin(int max_w){
	max_weight = max_w;
}


int Cabin::addPassengersGroup(PeopleGroup* group){
	if(curr_weight + group->getWeight() > max_weight){
		return 0;
	}else{
		passengers_group.insert(std::make_pair(group->getGoalFloor() ,  group));
		return 1;
	}
}

PeopleGroup* Cabin::removePassengersGroup(int exit_floor){//переписать
	PeopleGroup* g = nullptr;
	std::multimap<int , PeopleGroup*>::iterator it =  passengers_group.find(exit_floor);
	if(it != passengers_group.end()){
		g = it->second;
		passengers_group.erase(it);
		return g = it->second;
	}else return nullptr;
}

std::multimap<int , PeopleGroup*>& Cabin::getPassengers(){
	return passengers_group;
}