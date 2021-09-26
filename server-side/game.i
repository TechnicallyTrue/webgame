%include <std_string.i>
%module game

%{
	#include "game.hpp"
	Game start();
%}

%include "game.hpp"
Game start();
