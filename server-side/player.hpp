#include "state.hpp"

using namespace std;

class Player{
	public:
		bool vampire;
		int health;
		House * house;
		Room * pos;
		Player * opponent;
		string action(string command, string object="");
		string use(string item);
		string attack();
		string goTo(string room);
		string lookAt(string item);
		Player(bool isVampire, Room * start);
};
