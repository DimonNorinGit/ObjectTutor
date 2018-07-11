

class PeopleGroup
{

	enum{ MAX_PEOPLE_IN_FLOOR = 5 , MAX_PEOPLE_WEIGHT = 120};
	int people_count;
	int curr_floor;
	int total_weight;
	int goal_floor;

public:
	PeopleGroup(int floor_count , int c_floor);

	int getWeight();

	int getGoalFloor();

};