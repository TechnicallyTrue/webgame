#include <iostream>
#include "game.hpp"

using namespace std;

int main(){
	Game newGame;
	cout << newGame.p1Action("goto", "lower landing") << endl;
	cout << newGame.p1Action("use", "lever") << endl;
	cout << newGame.p1Action("goto", "entrance") << endl;
	cout << newGame.p1Action("goto", "drawing room") << endl;
	cout << newGame.p1Action("use", "lever") << endl;
	cout << newGame.p1Action("use", "blah") << endl;
	cout << newGame.p1Action("attack") << endl;
	cout << newGame.p2Action("goto", "lower landing") << endl;
	cout << newGame.p2Action("goto", "dining room") << endl;
	cout << newGame.p2Action("attack") << endl;
	cout << newGame.p2Action("goto", "drawing room") << endl;
	cout << newGame.p2Action("attack") << endl;
}
