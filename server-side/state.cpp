#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "state.hpp"

using namespace std;

/*string Item::interact(string action){
	/*stringstream message;
	if(action == "Use"){
		message << "Used " << itemName << endl;
	}else if(action == "Inspect"){
		message << description << endl;
	}
	return message.str();
	return "You use the " + itemName + ".";
}*/

Item::Item(string name){
	itemName = name;
}

Lever::Lever(string name, bool pos) : Item(name){
	itemName = name;
	up = pos;
	description = "Pulling this lever will help unlock the front doors.";
	interact = "You pulled the lever.";
}

Room::Room(string name, House * mansion){
	roomName = name;
	house = mansion;
}

string Room::describe(){
	stringstream message;
	message << "You are in the " << roomName << "." << endl;
	for(int i = 0; i < roomItems.size(); i++){
		message << " There is a " << roomItems[i]->itemName << ".";
	}
	message << endl;
	message << "From here you can reach ";
	for(int i = 0; i < adjRooms.size() - 1; i++){
		message << "the " << adjRooms[i]->roomName << ", ";
	}
	message << "and the " << adjRooms[adjRooms.size() - 1]->roomName << "." << endl;
	return message.str();
}

House::House(){
	unlocked = false;
	escaped = false;
}

string test(){
	House * house = new House();
	Room livingRoom("living room", house);
	Item * lamp = new Item("lamp");
	Item * table = new Item("table");
	livingRoom.roomItems.push_back(lamp);
	livingRoom.roomItems.push_back(table);
	return livingRoom.describe();
}
