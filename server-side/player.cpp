#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <time.h>
#include "player.hpp"

using namespace std;

Player::Player(bool isVampire, Room * start){
	vampire = isVampire;
	pos = start;
	if(!vampire){
		health = 3;
	}
}

string Player::action(string command, string object){
	if(command == "use"){
		return use(object);
	}else if(command == "attack" && vampire){
		return attack();
	}else if(command == "go to"){
		return goTo(object);
	}else if(command == "look at"){
		return lookAt(object);
	}else{
		return "That's not something you can do.";
	}
}

string Player::use(string item){
	vector<Item*> vec = pos->roomItems;
	//auto itr = find_if(vec.begin(), vec.end(), [](state::Item i){return i.})
	for(int i = 0; i < vec.size(); i++){
		if(vec[i]->itemName == item){
			if(item == "lever"){
				if(vampire){
					return "Why would you want to do that?";
				}
				vec[i]->up = !vec[i]->up;
				for(int j = 0; j < house->levers.size(); j++){
					if(house->levers[j]->up == false){
						return vec[i]->interact;
					}
				}
				house->unlocked = true;
				house->exit->description = "The doors are now unlocked.";
				return vec[i]->interact + " You hear the front doors unlock!";
			}else if(item == "door" && house->unlocked){
				house->escaped = true;
				return "Unlocking the door, you quickly make your escape!\n!!!YOU WIN!!!";
			}
			return vec[i]->interact;
		}
	}
	return "This room doesn't have a(n) " + item + ".";
}

string Player::attack(){
	if (opponent->pos == pos){
		srand(time(0));
		int hit = rand() % 4;
		switch(hit){
			case 0:
				return "You miss!";
			default:
				opponent->health--;
				if(opponent->health <= 0){
					//end game
					return "The tasty human slumps to the floor, bleeding out. Time for dinner.";
				}
				return "You deal your opponent a glancing blow.";
		}
	}
	return "No one to attack in this room.";
}

string Player::goTo(string room){
	vector<Room*> vec = pos->adjRooms;
	//auto itr = find_if(vec.begin(), vec.end(), [](state::Item i){return i.})
	for(int i = 0; i < vec.size(); i++){
		if(vec[i]->roomName == room){
			pos = vec[i];
			return vec[i]->describe();
		}
	}
	return "You can't reach the " + room + " from here.";
}

string Player::lookAt(string item){
	if(item == pos->roomName){
		return pos->describe();
	}
	vector<Item*> vec = pos->roomItems;
	//auto itr = find_if(vec.begin(), vec.end(), [](state::Item i){return i.})
	for(int i = 0; i < vec.size(); i++){
		if(vec[i]->itemName == item){
			return vec[i]->description;
		}
	}
	return "This room doesn't have a(n) " + item + ".";
}

