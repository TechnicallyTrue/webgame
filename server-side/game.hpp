#include "player.hpp"

using namespace std;

const string helpText = "You can 'look at', 'go to', or 'use'. Try to find a way out!";

class Game{
	public:
		Player * vampire;
		Player * victim;
		House * house;
		Game();
		string p1Action(string command, string object="");
		string p2Action(string command, string object="");
		int isOver();
		string intro();
};
