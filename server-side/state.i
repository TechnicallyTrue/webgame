%include <std_string.i>
%module state

%{
	#include "state.hpp"
	string test();
	
%}

%include "state.hpp"
string test();

