#include"LiftDriver.h"


Driver::Driver(int floor_c){
		floor_count = floor_c;
		PassengersInDay = 0;
		curr_floor = 1;
		curr_goal = 0;
		isEmpty = true;
}


int Driver::getCurrentFloor(){
	return curr_floor;
}

void Driver::addToCalls(int floor){
	calls_lift.push(floor);
}

void Driver::addToCommands(int floor){
	commands_lift.push(floor);
}

LiftState Driver::executeNextCommand(std::vector< std::pair< PeopleGroup* , int > >& floors_group ,  std::multimap<int , PeopleGroup*>& passengers){
	if(!isEmpty){
		return executeCommandInLift(floors_group , passengers);
	}else{
		return executeCallCommand();
	}
}
	

LiftState Driver::executeCallCommand(){
	if(!curr_goal){
		if(calls_lift.empty()){
			return WAITING;
		}else{
			curr_goal = calls_lift.front();
			calls_lift.pop();
		}
	}
	if(curr_floor < curr_goal){
		curr_floor++;
		return MOVE;
	}else if(curr_floor > curr_goal){
		curr_floor--;
		return MOVE;
	}else{
		curr_goal = 0;
		isEmpty = false;
		return SET;
	}
}

LiftState Driver::executeCommandInLift(std::vector< std::pair< PeopleGroup* , int > >& floors_group , std::multimap<int , PeopleGroup*>& passengers){

	if(!curr_goal){
		if(commands_lift.empty()){//add :when there is not empty floor 
			isEmpty = true;
			return WAITING;
		}
		curr_goal = commands_lift.front();///empty()?
		commands_lift.pop();
	}



	if(curr_floor < curr_goal){
		curr_floor++;
		if(floors_group[curr_floor].first != 0 && curr_floor < floors_group[curr_floor].second){
			if(floors_group[curr_floor].second < curr_goal){
				commands_lift.push(curr_goal);
				curr_goal = floors_group[curr_floor].second;
			}else if(floors_group[curr_floor].second != curr_goal){
				commands_lift.push(floors_group[curr_floor].second);
			}
			return SET;
		}
		return MOVE;
	}else if(curr_floor > curr_goal){
		curr_floor--;
		if(floors_group[curr_floor].first != 0 && curr_floor > floors_group[curr_floor].second){
			if(floors_group[curr_floor].second > curr_goal){
				commands_lift.push(curr_goal);
				curr_goal = floors_group[curr_floor].second;
			}else if(floors_group[curr_floor].second != curr_goal){
				commands_lift.push(floors_group[curr_floor].second);
			}
			return SET;
		}
		return MOVE;
	}else{
		curr_goal = 0;
		return REMOVE;
	}


	/*int PassengersInDay;
	int floor_count;
	int curr_floor;
	int curr_goal;
	LiftState curr_state;
	bool isEmpty;
	std::queue<int> calls_lift;
	std::queue<int> commands_lift;*/
	//enum LiftState{MOVE , WAITING , SET , REMOVE};

}

