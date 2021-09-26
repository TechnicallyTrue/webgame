#include <string>
#include <vector>
#include <map>

using namespace std;

class Item{
	public:		
		bool up;
		string itemName;
		string interact;
		string description;
		bool isVisible;
		Item(string name);
		//Item(string name) : itemName(name) {}
		//Item() : itemName("ERROR") {}
		//Item(){itemName = "ERROR";}
};

class Lever: public Item{
	public:
		Lever(string name, bool pos);
};

class House{
	public:
		vector<Lever*> levers;
		Item * exit;
		House();
		bool unlocked;
		bool escaped;
};

class Room{
	public:
		string roomName;
		vector<Room*> adjRooms;
		vector<Item*> roomItems;
		string describe();
		House * house;
		Room(string name, House * mansion);
		//Room(string name) : roomName(name) {}
		//Room() : roomName("ERROR") {}
		//Room(){roomName = "ERROR";}
};
