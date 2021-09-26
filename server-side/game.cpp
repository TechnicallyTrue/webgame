#include "game.hpp"

using namespace std;

Game::Game(){
	//Build rooms
	house = new House();
	Room *entrance = new Room("entrance", house);
	Room *lowerLanding = new Room("lower landing", house);
	Room *conservatory = new Room("conservatory", house);
	Room *study = new Room("study", house);
	Room *sittingRoom = new Room("sitting room", house);
	Room *library = new Room("library", house);
	Room *drawingRoom = new Room("drawing room", house);
	Room *diningRoom = new Room("dining room", house);
	Room *kitchen = new Room("kitchen", house);
	/*Room *masterBedroom = new Room("master bedroom", house);
	Room *upperLanding = new Room("upper landing", house);
	Room *storageRoom = new Room("storage room", house);
	Room *bathroom = new Room("bathroom", house);
	Room *guestBedroom = new Room("guest bedroom", house);
	Room *trophyRoom = new Room("trophy room", house);
	Room *gallery = new Room("gallery", house);
	Room *musicRoom = new Room("music room", house);
	Room *staffQuarters = new Room("staff quarters", house);*/

	//Connect rooms
	entrance->adjRooms.push_back(lowerLanding);
	entrance->adjRooms.push_back(study);
	entrance->adjRooms.push_back(drawingRoom);
	lowerLanding->adjRooms.push_back(entrance);
	lowerLanding->adjRooms.push_back(diningRoom);
	lowerLanding->adjRooms.push_back(sittingRoom);
	conservatory->adjRooms.push_back(kitchen);
	conservatory->adjRooms.push_back(library);
	study->adjRooms.push_back(entrance);
	study->adjRooms.push_back(sittingRoom);
	sittingRoom->adjRooms.push_back(study);
	sittingRoom->adjRooms.push_back(lowerLanding);
	sittingRoom->adjRooms.push_back(library);
	library->adjRooms.push_back(sittingRoom);
	library->adjRooms.push_back(conservatory);
	drawingRoom->adjRooms.push_back(entrance);
	drawingRoom->adjRooms.push_back(diningRoom);
	diningRoom->adjRooms.push_back(drawingRoom);
	diningRoom->adjRooms.push_back(lowerLanding);
	diningRoom->adjRooms.push_back(kitchen);
	kitchen->adjRooms.push_back(diningRoom);
	kitchen->adjRooms.push_back(conservatory);

	//Create and place levers
	Lever *lever1 = new Lever("lever", false);
	Lever *lever2 = new Lever("lever", false);
	Lever *lever3 = new Lever("lever", false);
	Lever *lever4 = new Lever("lever", false);
	house->levers.push_back(lever1);
	house->levers.push_back(lever2);
	house->levers.push_back(lever3);
	house->levers.push_back(lever4);
	drawingRoom->roomItems.push_back(lever1);
	study->roomItems.push_back(lever2);
	lowerLanding->roomItems.push_back(lever3);
	conservatory->roomItems.push_back(lever4);

	//Create and place exit
	Item *door = new Item("door");
	house->exit = door;
	door->interact = "The front doors are locked tight. Pull all the levers to escape.";
	door->description = "A pair of heavy, locked doors bars your escape. The levers throughout the house might unlock it.";
	entrance->roomItems.push_back(door);
	
	vampire = new Player(true, sittingRoom);
	victim = new Player(false, entrance);
	vampire->opponent = victim;
	vampire->house = house;
	victim->opponent = vampire;
	victim->house = house;
}

string Game::p1Action(string command, string object){
	if(command == "help"){
		return helpText + "\n\n" + victim->pos->describe();
	}
	return victim->action(command, object);
}

string Game::p2Action(string command, string object){
	return vampire->action(command, object);
}

int Game::isOver(){
	if(house->escaped){
		return 1;
	}
	return 0;
}

Game start(){
	Game newGame;
	return newGame;
}

string Game::intro(){
	string message = helpText + "\nPress 'help' at any time to review commands.\n\n" + vampire->pos->describe();
	return message;
}
