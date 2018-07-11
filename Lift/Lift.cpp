#include"Lift.h"
#include<iostream>
Lift::Lift(int max_weight , int floor_count){
		driver = new Driver(floor_count);///////
		cabin = new Cabin(max_weight);///////
		curr_floor = 1;
}

int Lift::getCurrentFloor(){
	return curr_floor;
}

void Lift::work(LiftShaft& lift_shaft ,  std::vector<bool>& isfloor_full){
	int exit_floor = 0;
	curr_state = driver->executeNextCommand(lift_shaft.getshaftFloors() ,   cabin->getPassengers());
	//enum LiftState{MOVE , WAITING , SET , REMOVE};
	PeopleGroup* gr = nullptr;
	switch(curr_state){

		case SET:
			curr_floor = driver->getCurrentFloor();
			gr = lift_shaft.removeFloorGroup(curr_floor);
			if(!cabin->addPassengersGroup(gr)){
				lift_shaft.setFloorGroup(curr_floor , gr);
				sendSignalToDriver(curr_floor);////
			}else{
				driver->addToCommands(gr->getGoalFloor());
				isfloor_full[curr_floor] = false;
				std::cout <<"Lift: " <<"s"<< curr_floor<<std::endl; 
			}
		break;

		case REMOVE:
			std::cout <<"Lift: " <<"r"<< curr_floor<<std::endl; 
			exit_floor = driver->getCurrentFloor();
			while(gr = cabin->removePassengersGroup(exit_floor)){
				delete gr;////
			}
			
		break;

		case MOVE:
		curr_floor = driver->getCurrentFloor();
		break;
		case WAITING:break;
	}



}


void Lift::sendSignalToDriver(int floor){
	driver->addToCalls(floor);
}
